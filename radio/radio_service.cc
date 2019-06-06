#include "radio_service.h"

#include "main/service_accessor.h"
#include "hmi/radio/radio_service_reciever.h"

namespace  {

HMIRadioStationInfo ConvertRadioLibInfoToHMIRadioInfo(const RadioStationInfo& info) {
  HMIRadioStationInfo result;
  result.station_id = info.station_id;
  result.station_name = info.station_name;
  return result;
}

}  // namespace

namespace radio {

RadioService::RadioService() {
}

void RadioService::Init()
{
  radio_service_reciever_ = ServiceAccessor::GetInstance().GetHMIService()->GetRadioServiceReciever();
}

void RadioService::OnStationDetected(RadioStationInfo info)
{
  std::cout << "RadioService";
  radio_service_reciever_->OnStationDetected(ConvertRadioLibInfoToHMIRadioInfo(info));
}

}  // namespace radio
