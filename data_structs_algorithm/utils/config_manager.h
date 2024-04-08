// Created by shawnunili on 2020/7/30.

#ifndef CPP_TOOLS_UTILS_CONFIG_MANAGER_H_
#define CPP_TOOLS_UTILS_CONFIG_MANAGER_H_

#include <atomic>
#include <string>
#include <vector>

class ConfigManager {
 public:
  struct ConfigData {
	std::string name;
	std::vector<std::string> list;
  };
 public:
  ConfigManager() : read_index_(0) {}
  void Init() {
	RefreshConfig();
  }

  const ConfigData &GetConfigData() {
	return config_data_[read_index_];
  }

  const std::string &GetName() {
	return config_data_[read_index_].name;
  }

 private:
  void SwapIndex() {
	read_index_ = (read_index_ == 0 ? 1 : 0);
  }
  void RefreshConfig();
 private:
  std::atomic<int> read_index_;
  ConfigData config_data_[2];
};

#endif //CPP_TOOLS_UTILS_CONFIG_MANAGER_H_
