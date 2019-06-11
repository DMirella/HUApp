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
  virtual void OnStationLost(int station_id) = 0;
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

  void EmulateStationLost(int station_frequency) {
    qDebug() << "EmulateStationLost: " << station_frequency;
    for (int i = 0; i < radio_stations_.size(); i++) {
      if (radio_stations_[i].station_frequency == station_frequency) {
        reciever_->OnStationLost(radio_stations_[i].station_id);
        radio_stations_.erase(radio_stations_.begin() + i);
        break;
      }
    }
  }

  void PlayRadioStation(int station_id) {
    qDebug() << "RadioLib::PlayRadioStation";
  }

  void StopCurrentRadioStation()  {
    qDebug() << "RadioLib::StopCurrentRadioStation";
  }

 private:
  std::shared_ptr<RadioLibReciever> reciever_;
  std::vector<RadioStationInfo> radio_stations_;
};

#endif // RADIOLIB_H
