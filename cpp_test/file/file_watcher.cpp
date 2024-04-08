/*inotify和epoll都是Linux内核提供的事件驱动IO机制。

inotify是Linux下一种文件监控机制，可以用来监控文件或者目录的变化，当被监控的文件或者目录发生变化时，inotify监控程序可以自动获得相应的事件信息，并且读取这些事件信息，从而可以监控到文件变化。

epoll是一种I/O事件通知被内核用来通知应用程序的新事件的方法。与select和poll类似，但epoll更为强大。它可以告诉应用程序哪些文件描述符可以进行IO操作，而不用等待应用程序需要轮询。这使得它对于在大量文件描述符中选择活动文件描述符非常有用，因此在高并发系统中广泛使用。

下面是一个使用epoll和inotify实现文件监听的示例：

*/
#include <errno.h>
#include <sys/epoll.h>
#include <sys/inotify.h>
#include <cstring>
#include <iostream>

#define MAX_EVENTS 1024
#define EVENT_SIZE (sizeof(struct inotify_event))
#define EVENT_BUF_LEN (MAX_EVENTS * (EVENT_SIZE + 16))

int main() {
  int fd = inotify_init();
  if (fd < 0) {
    perror("inotify_init");
    exit(EXIT_FAILURE);
  }

  int wd =
      inotify_add_watch(fd, "/path/to/file", IN_MODIFY | IN_CREATE | IN_DELETE);
  if (wd < 0) {
    perror("inotify_add_watch");
    exit(EXIT_FAILURE);
  }

  int epoll_fd = epoll_create1(0);
  if (epoll_fd < 0) {
    perror("epoll_create1");
    exit(EXIT_FAILURE);
  }

  struct epoll_event event, events[MAX_EVENTS];
  memset(&event, 0, sizeof(event));
  event.events = EPOLLIN | EPOLLET;
  event.data.fd = fd;
  if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event) < 0) {
    perror("epoll_ctl");
    exit(EXIT_FAILURE);
  }

  char buffer[EVENT_BUF_LEN];
  while (true) {
    int num = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
    if (num < 0) {
      perror("epoll_wait");
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num; ++i) {
      if (events[i].data.fd == fd) {
        int length = read(fd, buffer, EVENT_BUF_LEN);
        if (length < 0) {
          perror("read");
          exit(EXIT_FAILURE);
        }

        int i = 0;
        while (i < length) {
          struct inotify_event *event = (struct inotify_event *)&buffer[i];
          if (event->len) {
            if (event->mask & IN_CREATE) {
              std::cout << "File created: " << event->name << std::endl;
            } else if (event->mask & IN_DELETE) {
              std::cout << "File deleted: " << event->name << std::endl;
            } else if (event->mask & IN_MODIFY) {
              std::cout << "File modified: " << event->name << std::endl;
            }
          }
          i += EVENT_SIZE + event->len;
        }
      }
    }
  }

  close(epoll_fd);
  close(fd);

  return 0;
}
/*
首先，我们使用inotify_init函数初始化inotify实例，并使用inotify_add_watch函数将文件加入监控列表。然后，我们通过epoll_create1函数创建一个epoll实例，使用epoll_ctl函数将inotify实例添加到epoll实例中，并将事件类型设置为EPOLLIN
|
EPOLLET以进行读取操作。最后，我们使用epoll_wait函数等待事件的发生，读取inotify实例中的事件信息并处理它们。

需要注意的是，上述示例中`/path/to/file`需要替换为您要监听的文件路径，同时，示例中使用了两个无限循环，分别在等待epoll事件和处理inotify事件。在实际使用中，您需要控制这两个循环的终止条件，以避免程序无法终止。*/