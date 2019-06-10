#ifndef RADIO_SERVICE_H
#define RADIO_SERVICE_H

#include "radiolib.h"
#include "hmi_radio_reciever.h"
#include "main/lib_manager.h"

#include <QMessageBox>

class RadioServiceReciever;

namespace radio {

class RadioService : public RadioLibReciever
                   , public HMIRadioReciever {
 public:
  RadioService(const RadioService& service) = delete;
  RadioService(RadioService&& service) = delete;
  RadioService& operator=(const RadioService& service) = delete;
  RadioService& operator=(RadioService&& service) = delete;

  RadioService();
  ~RadioService() {}

  void Init();

 private:
  // RadioLibReciever
  void OnStationDetected(RadioStationInfo info) override;

  // HMIRadioReciever
  void onStationChanged(int station_id) override {}
  void onRadioScreenShow() override {
  }

  std::shared_ptr<RadioServiceReciever> radio_service_reciever_;
};

}  // namespace radio

#endif // RADIO_SERVICE_H
