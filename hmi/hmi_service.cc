#include "hmi_service.h"

#include <QObject>

#include "hmi/radio/radio_service_reciever.h"

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

void QHMISignalSender::Init()
{
  connect(&(hmi_service_->sender_),
          SIGNAL(StationDetected(HMIRadioStationInfo)),
          &(hmi_service_->main_window_.radio_screen_),
          SLOT(OnStationDetected(HMIRadioStationInfo)));
}

}  // hmi
