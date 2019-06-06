#ifndef LIB_MANAGER_H
#define LIB_MANAGER_H

#include <memory>

#include "media/btmedialib.h"
#include "radio/radiolib.h"
#include "main/service_accessor.h"
#include "tools/boostc++11.h"

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

  void Init() {
    btmedia_lib_ = boostcc11::make_unique<BTMediaLib>(
          ServiceAccessor::GetInstance().GetMediaService());
    radio_lib_ = boostcc11::make_unique<RadioLib>(
          ServiceAccessor::GetInstance().GetRadioService());
  }
private:
  LibManager() {}

  std::unique_ptr<BTMediaLib> btmedia_lib_;
  std::unique_ptr<RadioLib> radio_lib_;
};

#endif // LIB_MANAGER_H
