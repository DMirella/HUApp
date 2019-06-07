#ifndef RADIO_SERVICE_RECIEVER_H
#define RADIO_SERVICE_RECIEVER_H

#include <QObject>
#include <string>

struct HMIRadioStationInfo {
  int station_id;
  std::string station_name;
};

class RadioServiceReciever : public QObject {
    Q_OBJECT
 public:
  RadioServiceReciever() {}
  virtual void OnStationDetected(HMIRadioStationInfo info) = 0;
};

#endif // RADIO_SERVICE_RECIEVER_H
