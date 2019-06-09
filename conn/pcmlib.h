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
  std::vector<Techology> enable_technologies_;
};

class PCMLibReciever {
 public:
  virtual void OnDeviceDetected(const PCMDeviceInfo& info) = 0;
};

class PCMLib {
 public:
  PCMLib(std::shared_ptr<PCMLibReciever> reciever)
    : reciever_(reciever) {
  }

  void TempTest() {
    // Temp
    PCMDeviceInfo info;
    info.device_id = 1;
    info.device_name = "Meizu";
    info.enable_technologies_.push_back(PCMDeviceInfo::Techology::CarPlay);
    reciever_->OnDeviceDetected(info);
  }

 private:
  std::shared_ptr<PCMLibReciever> reciever_;
};

#endif // PCMLIB_H
