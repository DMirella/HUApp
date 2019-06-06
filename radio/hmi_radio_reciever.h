#ifndef HMI_RADIO_RECIEVER_H
#define HMI_RADIO_RECIEVER_H

class HMIRadioReciever {
 public:
  virtual void onStationChanged(int station_id) = 0;
  virtual void onRadioScreenShow() = 0;
};

#endif // HMI_RADIO_RECIEVER_H
