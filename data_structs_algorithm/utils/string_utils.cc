//
// Created by shawnunili on 2020/7/30.
//
#include "string_utils.h"

namespace xct {
void Split(const std::string &str, const std::string &sep, bool flag, std::vector<std::string> &result) {
  int pos1, pos2;
  int len = sep.length();
  pos1 = 0;
  pos2 = str.find(sep);
  while (pos2 != std::string::npos) {
	const auto &ele = str.substr(pos1, pos2 - pos1);
	if (!ele.empty()) {
	  result.emplace_back(ele);
	} else if (flag) {
	  result.emplace_back(ele);
	}
	pos1 = pos2 + len;
	pos2 = str.find(sep, pos1);
  }
  std::string ele;
  if (pos1 < str.length()) {
	ele = str.substr(pos1);
  }
  if (!ele.empty()) {
	result.emplace_back(ele);
  } else if (flag) {
	result.emplace_back(ele);
  }
}
// 此特殊版本是对于\sep这种格式的不算分隔符
void SplitWithEscape(const std::string &str, const std::string &sep, bool flag, std::vector<std::string> &result) {
  int pos1, pos2;
  int len = sep.length();
  pos1 = 0;
  pos2 = str.find(sep);
  while (pos2 != std::string::npos) {
	if (pos2 == 0 || (pos2 > 0 && str[pos2 - 1] != '\\')) {
	  const auto &ele = str.substr(pos1, pos2 - pos1);
	  if (!ele.empty()) {
		result.emplace_back(ele);
	  } else if (flag) {
		result.emplace_back(ele);
	  }
	  pos1 = pos2 + len;
	  pos2 = str.find(sep, pos1);
	} else {
	  // 找到的是转义的
	  pos2 += len;
	  pos2 = str.find(sep, pos2);
	}
  }
  std::string ele;
  if (pos1 < str.length()) {
	ele = str.substr(pos1);
  }
  if (!ele.empty()) {
	result.emplace_back(ele);
  } else if (flag) {
	result.emplace_back(ele);
  }
}
}