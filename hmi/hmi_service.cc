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

void HMIService::OnBTMediaDeviceDetected(HMIMediaDeviceInfo info)
{
    sender_.OnBTMediaDeviceDetected(info);
}

void HMIService::OnPCMDeviceDetected(HMIPCMDeviceInfo info)
{
    sender_.OnPCMDeviceDetected(info);
}

void QHMISignalSender::Init()
{
  connect(&(hmi_service_->sender_),
          SIGNAL(StationDetected(HMIRadioStationInfo)),
          &(hmi_service_->main_window_.radio_screen_),
          SLOT(OnStationDetected(HMIRadioStationInfo)));

  connect(&(hmi_service_->sender_),
          SIGNAL(BTMediaDeviceDetected(HMIMediaDeviceInfo)),
          &(hmi_service_->main_window_.media_screen_),
          SLOT(OnBTMediaDeviceDetected(HMIMediaDeviceInfo)));

  connect(&(hmi_service_->sender_),
          SIGNAL(PCMDeviceDetected(HMIPCMDeviceInfo)),
          &(hmi_service_->main_window_.phone_screen_),
          SLOT(OnPCMDeviceDetected(HMIPCMDeviceInfo)));
}

}  // hmi
