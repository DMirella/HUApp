#ifndef RADIOLIB_H
#define RADIOLIB_H

#include <string>
#include <memory>

struct RadioStationInfo {
  int station_id;
  int station_frequency;
  std::string station_name;
};

class RadioLibReciever {
 public:
    virtual void OnStationDetected(RadioStationInfo info) = 0;
};

class RadioLib {
 public:
  RadioLib(std::shared_ptr<RadioLibReciever> reciever)
    : reciever_(reciever) {
    // Temp
    RadioStationInfo info;
    info.station_id = 1;
    info.station_frequency = 20;
    info.station_name = "Radio tapok";
  }

  void PlayRadioStation(int station_id) {}
 private:
  std::shared_ptr<RadioLibReciever> reciever_;
};

#endif // RADIOLIB_H
