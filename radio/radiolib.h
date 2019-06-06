#ifndef RADIOLIB_H
#define RADIOLIB_H

#include <string>
#include <memory>

struct RadioStationInfo {
  int device_id;
  std::string device_name;
  std::string song_name;
};

class RadioLibReciever {
 public:
};

class RadioLib {
 public:
  RadioLib(RadioLibReciever* reciever)
    : reciever_(reciever) {
  }
 private:
  std::shared_ptr<RadioLibReciever> reciever_;
};

#endif // RADIOLIB_H
