#include "hmi_service.h"

#include <QObject>

#include "hmi/radio/radio_service_reciever.h"

namespace hmi {

HMIService::HMIService()
  : sender_(std::make_shared<HMIService>(this)) {

}

void HMIService::start() {
  main_window_.Init();
  main_window_.show();
}

void HMIService::OnStationDetected(HMIRadioStationInfo info)
{

}

void QHMISignalSender::Init()
{
  connect(hmi_service_->sender_,
          &(hmi_service_->sender_.StationDetected(HMIRadioStationInfo),
          &(hmi_service_->main_window_.radio_screen_),
          &(hmi_service_->main_window_.radio_screen_.OnStationDetected(HMIRadioStationInfo)));
}

}  // hmi
