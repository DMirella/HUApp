#ifndef LIB_MANAGER_H
#define LIB_MANAGER_H

#include <memory>

#include "tools/boostc++11.h"

class BTMediaLib;
class RadioLib;

class LibManager
{
public:
  LibManager(const LibManager& lib_manager) = delete;
  LibManager(LibManager&& lib_manager) = delete;
  LibManager& operator=(const LibManager& lib_manager) = delete;
  LibManager& operator=(LibManager&& lib_manager) = delete;

  static LibManager& GetInstance() {
    static LibManager lib_manager;
    return lib_manager;
  }
  ~LibManager() {}

  void Init();

  std::shared_ptr<RadioLib> GetRadioLib() const {
    return radio_lib_;
  }
private:
  LibManager() {}

  std::shared_ptr<BTMediaLib> btmedia_lib_;
  std::shared_ptr<RadioLib> radio_lib_;
};

#endif // LIB_MANAGER_H
