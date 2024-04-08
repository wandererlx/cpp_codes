//
// Created by shawnunili on 2020/7/30.
#ifndef CPP_TOOLS_UTILS_STRING_UTILS_H_
#define CPP_TOOLS_UTILS_STRING_UTILS_H_

#include <string>
#include <vector>

namespace xct {
void Split(const std::string &str, const std::string &sep, bool flag, std::vector<std::string> &result);

void SplitWithEscape(const std::string &str, const std::string &sep, bool flag, std::vector<std::string> &result);
}

#endif //CPP_TOOLS_UTILS_STRING_UTILS_H_
