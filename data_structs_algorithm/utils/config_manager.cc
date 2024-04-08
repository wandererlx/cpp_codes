//
// Created by shawnunili on 2020/7/30.
//
#include "config_manager.h"
void ConfigManager::RefreshConfig() {
  auto &write_config = config_data_[read_index_ == 0 ? 1 : 0];
  write_config.name = "li";
  write_config.list.clear();
  write_config.list.push_back("xiao");
  SwapIndex();
}