#include "service_accessor.h"

ServiceAccessor::ServiceAccessor()
  : hmi_service_(std::make_shared<hmi::HMIService>()) {

}

ServiceAccessor& ServiceAccessor::GetInstance() {
  static ServiceAccessor service_accessor;
  return service_accessor;
}
