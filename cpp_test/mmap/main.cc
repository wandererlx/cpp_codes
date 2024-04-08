#include <fcntl.h>
#include <signal.h>
#include <sys/mman.h>
#include <unistd.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <atomic>

class CommMmap {
 public:
  void* Init(const std::string& file_name, size_t shm_size, bool flag) {
    file_name_ = file_name;
    shm_size_ = shm_size;
    if (flag) {
      // 创建共享内存区域
      shm_fd_ = shm_open(file_name.c_str(), O_CREAT | O_RDWR, 0644);
    } else {
      // 创建共享内存区域
      shm_fd_ = open(file_name.c_str(), O_RDWR);
    }
    if (shm_fd_ == -1) {
      return NULL;
    }
    // 设置共享文件大小
    if (ftruncate(shm_fd_, shm_size_) == -1) {
      close(shm_fd_);
      return NULL;
    }
    // 将共享内存区域映射到当前进程
    shm_address_ =
        mmap(NULL, shm_size_, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd_, 0);
    if (shm_address_ == MAP_FAILED) {
      close(shm_fd_);
      return NULL;
    }
    return shm_address_;
  }

  size_t GetShmSize() { return shm_size_; }

  int Destroy() {
    munmap(shm_address_, shm_size_);
    return close(shm_fd_);
  }

 private:
  std::string file_name_;
  size_t shm_size_;
  int shm_fd_;
  void* shm_address_;
};

CommMmap comm_map;
std::atomic<bool> flag{true};

void SigHandler(int sig_num) {
  flag.store(false);
  std::this_thread::sleep_for(std::chrono::seconds(3));
  comm_map.Destroy();
  exit(0);
}

int main(int argc, char* argv[]) {
  signal(SIGINT, SigHandler);
  void* buf = comm_map.Init("./mmap_disk_file_test", 1024 * 4, false);
  if (buf == nullptr) {
    printf("init mmap error\n");
  } else {
    int i = 0;
    char *buff = static_cast<char*>(buf);
    while (flag) {
      int write_size = sprintf(buff, "line %d: new line\n", i++);
      buff += write_size;
      printf("write %d: byte, sleep 10s\n", write_size);
      std::this_thread::sleep_for(std::chrono::seconds(10));
    }
  }
  return 0;
}