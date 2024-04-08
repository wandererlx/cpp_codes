#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/*
#include <windows.h>
#include <string>

std::string gbk_to_utf8(const std::string& str_gbk) {
    int len = MultiByteToWideChar(CP_ACP, 0, str_gbk.c_str(), -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, str_gbk.c_str(), -1, wstr, len);

    len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* str = new char[len];
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);

    std::string str_utf8 = str;

    delete[] wstr;
    delete[] str;

    return str_utf8;
}
*/

/*
```c++
#include <iconv.h>
#include <cerrno>
#include <cstring>
#include <string>

std::string gbk_to_utf8(const std::string& str_gbk) {
    iconv_t cd = iconv_open("UTF-8", "GBK");

    if (cd == static_cast<iconv_t>(-1)) {
        std::cerr << "Failed to open iconv: " << std::strerror(errno) <<
std::endl; return "";
    }

    char* inbuf = const_cast<char*>(str_gbk.c_str());
    size_t inbytesleft = str_gbk.size();

    size_t outbytesleft = inbytesleft * 4;
    char* outbuf = new char[outbytesleft];
    char* outptr = outbuf;

    if (iconv(cd, &inbuf, &inbytesleft, &outptr, &outbytesleft) ==
static_cast<size_t>(-1)) { std::cerr << "Failed to convert: " <<
std::strerror(errno) << std::endl; return "";
    }

    std::string str_utf8(outbuf, outptr - outbuf);

    delete[] outbuf;
    iconv_close(cd);

    return str_utf8;
}

*/

/*
std::string GBKToUTF8(const std::string& str) {
  std::filesystem::path path{str, std::locale("zh_CN.gbk")};
  return path.u8string();
}

int main(int argc, char* argv[]) {
  std::ifstream ifs("/home/data/chase_limit_up/config.csv");
  std::stringstream stream;
  //   stream << ifs.rdbuf();
  //   std::string gbk_str(stream.str());
  std::cout << "<----------------original gbk content----------------->"
            << std::endl;
  std::string line;
  int index = 1;
  while (std::getline(ifs, line)) {
    std::cout << "line " << index++ << "|" << line << std::endl;
    // //   // 将gb2312字符串转换为unicode编码
    // std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    // std::wstring wide_str = conv.from_bytes(line);

    // // 将unicode编码的字符串转换为utf-8编码
    // std::string utf8_str = conv.to_bytes(wide_str);

    // // 输出utf-8编码的字符串
    // std::cout << utf8_str << std::endl;
    std::cout << GBKToUTF8(line) << std::endl;
  }
  // std::cout << "<----------------utf-8 content----------------->" <<
  // std::endl;

  return 0;
}
*/

#include <iostream>
#include <vector>

using namespace std;

// 将GBK字符转换为Unicode字符
int gbk_to_unicode(const char* gbk, int len, wchar_t* unicode) {
  int i = 0;
  int j = 0;
  while (i < len) {
    if ((gbk[i] & 0x80) == 0) {  // 单字节字符
      unicode[j++] = (wchar_t)gbk[i++];
    } else {  // 双字节字符
      unsigned char high_byte = gbk[i++];
      unsigned char low_byte = gbk[i++];

      if (high_byte >= 0x81 && high_byte <= 0xFE && low_byte >= 0x40 &&
          low_byte <= 0xFE && low_byte != 0x7F) {
        // 合法的GBK编码，进行转换
        unsigned short tmp = ((unsigned short)(high_byte - 0x81) << 9) +
                             ((unsigned short)(low_byte - 0x40));
        if (tmp < 0xFFE0) {
          tmp -= 0x3C20;
        }
        unicode[j++] = (wchar_t)tmp;
      } else {
        // 非法的GBK编码，忽略
      }
    }
  }
  return j;  // 返回转换后的Unicode字符个数
}

// 将Unicode字符转换为UTF-8字符
void unicode_to_utf8(wchar_t unicode, vector<char>& utf8) {
  if (unicode <= 0x7F) {  // ASCII字符
    utf8.push_back((char)unicode);
  } else if (unicode <= 0x7FF) {  // 双字节字符
    utf8.push_back((char)(0xC0 | (unicode >> 6)));
    utf8.push_back((char)(0x80 | (unicode & 0x3F)));
  } else if (unicode <= 0xFFFF) {  // 三字节字符
    utf8.push_back((char)(0xE0 | (unicode >> 12)));
    utf8.push_back((char)(0x80 | ((unicode >> 6) & 0x3F)));
    utf8.push_back((char)(0x80 | (unicode & 0x3F)));
  } else {  // 四字节字符（不支持）
            // 忽略
  }
}

std::string ConvertGBKToUTF8(const std::string& str) {
  wchar_t* unicode_str = new wchar_t[str.size() + 1];
  int unicode_len = gbk_to_unicode(str.c_str(), str.size(), unicode_str);
  unicode_str[unicode_len] = L'\0';
  vector<char> utf8_str;
  for (int i = 0; i < unicode_len; i++) {
    unicode_to_utf8(unicode_str[i], utf8_str);
  }
  utf8_str.push_back('\0');
  string tmp(&utf8_str[0]);
  delete[] unicode_str;
  return tmp;
}

/*int main() {
  const char* gbk_str = "中文GBK编码";  // GBK编码的字符串
  int gbk_len = strlen(gbk_str);

  // 将GBK编码转换为Unicode字符
  wchar_t* unicode_str = new wchar_t[gbk_len + 1];
  int unicode_len = gbk_to_unicode(gbk_str, gbk_len, unicode_str);
  unicode_str[unicode_len] = L'\0';

  // 将Unicode字符转换为UTF-8编码
  vector<char> utf8_str;
  for (int i = 0; i < unicode_len; i++) {
    unicode_to_utf8(unicode_str[i], utf8_str);
  }

  // 输出UTF-8编码的结果
  for (auto c : utf8_str) {
    printf("\\%03o", (unsigned char)c);  // 输出八进制表示的字符
  }
  printf("\n");

  delete[] unicode_str;

  return 0;
}*/

int main(int argc, char* argv[]) {
  std::ifstream ifs("/home/data/chase_limit_up/config.csv");
  std::stringstream stream;
  //   stream << ifs.rdbuf();
  //   std::string gbk_str(stream.str());
  std::cout << "<----------------original gbk content----------------->"
            << std::endl;
  std::string line;
  int index = 1;
  std::ofstream ofs("./output");
  while (std::getline(ifs, line)) {
    std::cout << "line " << index++ << "|" << line << std::endl;
    // //   // 将gb2312字符串转换为unicode编码
    // std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    // std::wstring wide_str = conv.from_bytes(line);

    // // 将unicode编码的字符串转换为utf-8编码
    // std::string utf8_str = conv.to_bytes(wide_str);

    // // 输出utf-8编码的字符串
    // std::cout << utf8_str << std::endl;
    ofs << ConvertGBKToUTF8(line);
  }
  // std::cout << "<----------------utf-8 content----------------->" <<
  // std::endl;

  return 0;
}