#include "service_accessor.h"

ServiceAccessor::ServiceAccessor()
  : hmi_service_(std::make_shared<hmi::HMIService>())
  , media_service_(std::make_shared<media::MediaService>())
  , radio_service_(std::make_shared<radio::RadioService>()) {

}

ServiceAccessor& ServiceAccessor::GetInstance() {
  static ServiceAccessor service_accessor;
  return service_accessor;
}
