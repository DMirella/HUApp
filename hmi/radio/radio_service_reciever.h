#ifndef RADIO_SERVICE_RECIEVER_H
#define RADIO_SERVICE_RECIEVER_H

#include <string>

struct HMIRadioStationInfo {
  int station_id;
  std::string station_name;
};

class RadioServiceReciever {
 public:
  RadioServiceReciever() {}
  virtual void OnStationDetected(HMIRadioStationInfo info) {}
};

#endif // RADIO_SERVICE_RECIEVER_H
