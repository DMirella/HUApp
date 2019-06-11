#ifndef PCMLIB_H
#define PCMLIB_H

#include <string>
#include <memory>
#include <vector>

#include <QDebug>

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
  virtual void OnPhoneMediaStart() = 0;
  virtual void OnPhoneMediaStop() = 0;
  virtual void OnPhonePhonecallStart() = 0;
  virtual void OnPhonePhonecallStop() = 0;
  virtual void OnPhoneNavigationStart() = 0;
  virtual void OnPhoneNavigationStop() = 0;
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

  void EmulateRequestPhoneMediaStart() {
    qDebug() << "Start phone media requested";
    reciever_->OnPhoneMediaStart();
    qDebug() << "Start phone media successful finished!";
  }

  void EmulateRequestPhoneMediaStop() {
    qDebug() << "Stop phone media requested";
    reciever_->OnPhoneMediaStop();
    qDebug() << "Stop phone media successful finished!";
  }

  void EmulateRequestPhonecallStart() {
    qDebug() << "Start phonecall requested";
    reciever_->OnPhonePhonecallStart();
    qDebug() << "Start phonecall successful finished!";
  }

  void EmulateRequestPhonecallStop() {
    qDebug() << "Stop phonecall requested";
    reciever_->OnPhonePhonecallStop();
    qDebug() << "Stop phonecall successful finished!";
  }

  void EmulateRequestPhoneNavigationStart() {
    qDebug() << "Start phone navigation requested";
    reciever_->OnPhoneNavigationStart();
    qDebug() << "Start phone successful navigation finished!";
  }

  void EmulateRequestPhoneNavigationStop() {
    qDebug() << "Stop phone navigation requested";
    reciever_->OnPhoneNavigationStop();
    qDebug() << "Stop phone successful navigation successful finished!";
  }

  void ConnectDevice(int device_id, PCMDeviceInfo::Techology technology) {
    qDebug() << "PCMLib::ConnectDevice: success connect!";
  }

  void StopPhoneMedia() {
    qDebug() << "PCMLib::StopPhoneMedia: success stop media!";
  }

  void StopPhoneNavigation() {
    qDebug() << "PCMLib::StopPhoneMedia: success stop navigation!";
  }

 private:
  std::shared_ptr<PCMLibReciever> reciever_;
  std::vector<PCMDeviceInfo> enable_devices_;
};

#endif // PCMLIB_H
