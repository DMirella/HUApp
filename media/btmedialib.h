#ifndef BTMEDIALIB_H
#define BTMEDIALIB_H

#include <string>
#include <memory>

struct BTMediaDeviceInfo {
  int device_id;
  std::string device_name;
  std::string song_name;
};

class BTMediaLibReciever {
 public:
  virtual void OnDeviceDetected(const BTMediaDeviceInfo& info) = 0;
};

class BTMediaLib {
 public:
  BTMediaLib(std::shared_ptr<BTMediaLibReciever> reciever)
    : reciever_(reciever) {
  }

  void PlayBTMedia(int device_id) {}
 private:
  std::shared_ptr<BTMediaLibReciever> reciever_;
};

#endif // BTMEDIALIB_H
