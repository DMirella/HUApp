#ifndef BTMEDIALIB_H
#define BTMEDIALIB_H

#include <string>
#include <memory>
#include <vector>

#include <QDebug>

struct BTMediaDeviceInfo {
  int device_id;
  std::string btmac_adress;
  std::string device_name;
  std::string song_name;
};

class BTMediaLibReciever {
 public:
  virtual void OnDeviceDetected(const BTMediaDeviceInfo& info) = 0;
  virtual void OnDeviceLost(int device_id) = 0;
};

class BTMediaLib {
 public:
  BTMediaLib(std::shared_ptr<BTMediaLibReciever> reciever)
    : reciever_(reciever) {
  }

  void EmulateDeviceDetected(std::string btmac_adress,
                             std::string device_name,
                             std::string song_name) {
    BTMediaDeviceInfo info;
    info.btmac_adress = btmac_adress;
    info.device_name = device_name;
    info.song_name = song_name;
    info.device_id = media_devices_.size();
    media_devices_.push_back(info);
    reciever_->OnDeviceDetected(info);
  }

  void EmulateDeviceLost(std::string btmac_adress) {
    for (int i = 0; i < media_devices_.size(); i++) {
      if (media_devices_[i].btmac_adress == btmac_adress) {
        reciever_->OnDeviceLost(media_devices_[i].device_id);
        media_devices_.erase(media_devices_.begin() + i);
        break;
      }
    }
  }

  void PlayBTMedia(int device_id) {
    qDebug() << "BTMediaLib::PlayBTMedia successful start!";
  }

  void StopBTMedia(int device_id) {
    qDebug() << "BTMediaLib::StopBTMedia successful stop!";
  }

  void StopCurrentBTMedia() {
    qDebug() << "BTMediaLib::StopCurrentBTMedia successful stop!";
  }
 private:
  std::shared_ptr<BTMediaLibReciever> reciever_;
  std::vector<BTMediaDeviceInfo> media_devices_;
};

#endif // BTMEDIALIB_H
