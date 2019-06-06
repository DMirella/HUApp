#include "radio_service.h"

#include "main/service_accessor.h"

namespace radio {

RadioService::RadioService() {
  // radio_service_reciever_ = ServiceAccessor::GetInstance().GetHMIService()->GetRadioServiceReciever();
}

}  // namespace radio
