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
#include "hmi/media/media_service_reciever.h"
#include "hmi/phone/pcmservicereciever.h"

namespace hmi {

class HMIService;
class QHMISignalSender : public QObject {
  Q_OBJECT
 signals:
  void StationDetected(HMIRadioStationInfo info);
  void StationLost(int station_id);
  void MediaDeviceDetected(HMIMediaDeviceInfo info);
  void MediaDeviceLost(int device_id);
  void PCMDeviceDetected(HMIPCMDeviceInfo info);
  void PCMDeviceLost(int device_id);
 public:
  QHMISignalSender(std::shared_ptr<HMIService> hmi_service)
      : hmi_service_(hmi_service) {}
  void Init();

  void OnStationDetected(HMIRadioStationInfo info) {
      emit StationDetected(info);
  }
  void OnStationLost(int station_id) {
      emit StationLost(station_id);
  }
  void OnMediaDeviceDetected(HMIMediaDeviceInfo info) {
      emit MediaDeviceDetected(info);
  }
  void OnMediaDeviceLost(int device_id) {
      emit MediaDeviceLost(device_id);
  }
  void OnPCMDeviceDetected(HMIPCMDeviceInfo info) {
      emit PCMDeviceDetected(info);
  }
  void OnPCMDeviceLost(int device_id) {
      emit PCMDeviceLost(device_id);
  }
 private:
  std::shared_ptr<HMIService> hmi_service_;
};

class HMIService : public RadioServiceReciever
                 , public MediaServiceReciever
                 , public PCMServiceReciever {

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
  void OnStationDetected(HMIRadioStationInfo info) override;
  void OnStationLost(int station_id) override;

  // MediaServiceReciever interface
  void OnMediaDeviceDetected(HMIMediaDeviceInfo info) override;
  void OnMediaDeviceLost(int device_id) override;

  // PCMServiceReciever interface
  void OnPCMDeviceDetected(HMIPCMDeviceInfo info) override;
  void OnPCMDeviceLost(int device_id) override;
};

}  // hmi

#endif // HMI_SERVICE_H
