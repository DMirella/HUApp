#ifndef HMI_SERVICE_H
#define HMI_SERVICE_H

#include <QObject>
#include <QDebug>

#include <memory>
#include <iostream>

#include "main_window.h"

#include "hmi/radio/radio_screen.h"
#include "radio/hmi_radio_reciever.h"
#include "hmi/radio/radio_service_reciever.h"

namespace hmi {

class HMIService;
class QHMISignalSender : public QObject {
  Q_OBJECT
 signals:
  void StationDetected(HMIRadioStationInfo info);
 public:
  QHMISignalSender(std::shared_ptr<HMIService> hmi_service)
      : hmi_service_(hmi_service) {}
  void Init();

  void OnStationDetected(HMIRadioStationInfo info) {
      emit StationDetected(info);
  }
 private:
  std::shared_ptr<HMIService> hmi_service_;
};

class HMIService : public RadioServiceReciever {

 public:
  HMIService(const HMIService& service) = delete;
  HMIService(HMIService&& service) = delete;
  HMIService& operator=(const HMIService& service) = delete;
  HMIService& operator=(HMIService&& service) = delete;

  HMIService();
  ~HMIService() {}

  void start();

 private:
  friend class QHMISignalSender;

  MainWindow main_window_;
  QHMISignalSender sender_;

  // RadioServiceReciever interface
 public:
  void OnStationDetected(HMIRadioStationInfo info) override;
};

}  // hmi

#endif // HMI_SERVICE_H
