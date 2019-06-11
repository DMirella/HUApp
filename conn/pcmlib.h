#ifndef PCMLIB_H
#define PCMLIB_H

#include <string>
#include <memory>
#include <vector>

struct PCMDeviceInfo {
  enum Techology {
    CarPlay = 0,
    AndroidAuto,
    MirrorLink
  };

  int device_id;
  std::string device_name;
  std::vector<Techology> enable_technologies;
};

class PCMLibReciever {
 public:
  virtual void OnDeviceDetected(const PCMDeviceInfo& info) = 0;
  virtual void OnDeviceLost(int device_id) = 0;
};

class PCMLib {
 public:
  PCMLib(std::shared_ptr<PCMLibReciever> reciever)
    : reciever_(reciever) {
  }

  void EmulateDetectedDevice(std::string device_name,
                             std::vector<PCMDeviceInfo::Techology> enable_technologies) {
    PCMDeviceInfo info;
    info.device_id = enable_devices_.size();
    info.device_name = device_name;
    info.enable_technologies = std::move(enable_technologies);
    enable_devices_.push_back(info);
    reciever_->OnDeviceDetected(info);
  }

  void EmulateLostDevice(std::string device_name) {
    for (int i = 0; i < enable_devices_.size(); i++) {
      if (enable_devices_[i].device_name == device_name) {
        reciever_->OnDeviceLost(enable_devices_[i].device_id);
        enable_devices_.erase(enable_devices_.begin() + i);
        break;
      }
    }
  }

 private:
  std::shared_ptr<PCMLibReciever> reciever_;
  std::vector<PCMDeviceInfo> enable_devices_;
};

#endif // PCMLIB_H
