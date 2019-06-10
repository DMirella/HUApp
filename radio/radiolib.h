#ifndef RADIOLIB_H
#define RADIOLIB_H

#include <string>
#include <memory>
#include <iostream>
#include <vector>

#include <QDebug>

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
  }

  void EmulateStationDetected(std::string station_name, int station_frequency) {
    RadioStationInfo info;
    info.station_id  = radio_stations_.size();
    info.station_name = station_name;
    info.station_frequency = station_frequency;
    radio_stations_.push_back(info);
    reciever_->OnStationDetected(info);
  }

  void PlayRadioStation(int station_id) {}
 private:
  std::shared_ptr<RadioLibReciever> reciever_;
  std::vector<RadioStationInfo> radio_stations_;
};

#endif // RADIOLIB_H
