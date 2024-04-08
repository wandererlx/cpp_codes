#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/stat.h>
#endif

#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

int64_t GetFileLastTime(const std::string& file_path) {
#ifdef _WIN32
  HANDLE fileHandle = CreateFile(file_path.c_str(), GENERIC_READ,
                                 FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
  if (fileHandle == INVALID_HANDLE_VALUE) {
    return -1;
  }
  FILETIME creationTime, lastAccessTime, lastWriteTime;
  if (!GetFileTime(fileHandle, &creationTime, &lastAccessTime,
                   &lastWriteTime)) {
    CloseHandle(fileHandle);
    return -1;
  }
  CloseHandle(fileHandle);
  ULARGE_INTEGER lastWriteTime64;
  lastWriteTime64.LowPart = lastWriteTime.dwLowDateTime;
  lastWriteTime64.HighPart = lastWriteTime.dwHighDateTime;
  time_t unixTimestamp = (lastWriteTime64.QuadPart - 116444736000000000LL) / 1;
  return unixTimestamp;
#else
  struct stat fileInfo;
  if (stat(file_path.c_str(), &fileInfo) != 0) {
    return -1;
  }
  return fileInfo.st_mtime;
#endif
}

int main(int argc, char* argv[]) {
  // std::string test("Abc|=98");
  // std::string result(test.size(), ' ');
  // std::transform(test.begin(), test.end(), result.begin(), ::tolower);
  // // result = std::tolower(test);
  // std::cout << "lower:" << result << std::endl;
  // std::round(0.9);
  // round(0.9);
  // double a = 1.2345678911;
  // int64_t b = round(a * 100000000);
  // printf("a=%.8f,b=%lld, c=%.8f\n", a, b,  b / 100000000.0);
  double aa = 0.123456785001;
  char bb[1000] = {0};
  aa = round(aa * 100000000) / 100000000;
  printf("aa is %0.8f\n", aa);
  sprintf(bb,"%0.8f", aa);
  printf("bb is %s\n", bb);
  return 0;
}