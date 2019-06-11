#include "hmi_service.h"

#include <QObject>

#include "hmi/radio/radio_service_reciever.h"
#include "hmi/media/media_service_reciever.h"

namespace hmi {

HMIService::HMIService()
  : sender_(std::shared_ptr<HMIService>(this)) {

}

void HMIService::start() {
  main_window_.Init();
  sender_.Init();
  main_window_.show();
}

void HMIService::OnStationDetected(HMIRadioStationInfo info)
{
  sender_.OnStationDetected(info);
}

void HMIService::OnStationLost(int station_id)
{
  sender_.OnStationLost(station_id);
}

void HMIService::OnMediaDeviceDetected(HMIMediaDeviceInfo info)
{
  sender_.OnMediaDeviceDetected(info);
}

void HMIService::OnMediaDeviceLost(int device_id)
{
  sender_.OnMediaDeviceLost(device_id);
}

void HMIService::OnPCMDeviceDetected(HMIPCMDeviceInfo info)
{
  sender_.OnPCMDeviceDetected(info);
}

void HMIService::OnPCMDeviceLost(int device_id)
{
  sender_.OnPCMDeviceLost(device_id);
}

void QHMISignalSender::Init()
{
  connect(&(hmi_service_->sender_),
          SIGNAL(StationDetected(HMIRadioStationInfo)),
          &(hmi_service_->main_window_.radio_screen_),
          SLOT(OnStationDetected(HMIRadioStationInfo)));

  connect(&(hmi_service_->sender_),
          SIGNAL(StationLost(int)),
          &(hmi_service_->main_window_.radio_screen_),
          SLOT(OnStationLost(int)));

  connect(&(hmi_service_->sender_),
          SIGNAL(MediaDeviceDetected(HMIMediaDeviceInfo)),
          &(hmi_service_->main_window_.media_screen_),
          SLOT(OnMediaDeviceDetected(HMIMediaDeviceInfo)));

  connect(&(hmi_service_->sender_),
          SIGNAL(MediaDeviceLost(int)),
          &(hmi_service_->main_window_.media_screen_),
          SLOT(OnMediaDeviceLost(int)));

  connect(&(hmi_service_->sender_),
          SIGNAL(PCMDeviceDetected(HMIPCMDeviceInfo)),
          &(hmi_service_->main_window_.phone_screen_),
          SLOT(OnPCMDeviceDetected(HMIPCMDeviceInfo)));

  connect(&(hmi_service_->sender_),
          SIGNAL(PCMDeviceLost(int)),
          &(hmi_service_->main_window_.phone_screen_),
          SLOT(OnPCMDeviceLost(int)));
}

}  // hmi
