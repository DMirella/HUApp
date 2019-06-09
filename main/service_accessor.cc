#include "service_accessor.h"

ServiceAccessor::ServiceAccessor()
  : hmi_service_(std::make_shared<hmi::HMIService>())
  , media_service_(std::make_shared<media::MediaService>())
  , radio_service_(std::make_shared<radio::RadioService>())
  , pcm_service_(std::make_shared<pcm::PCMService>()) {

}

ServiceAccessor& ServiceAccessor::GetInstance() {
  static ServiceAccessor service_accessor;
  return service_accessor;
}

void ServiceAccessor::Init()
{
  assert(radio_service_ != nullptr);
  assert(media_service_ != nullptr);
  assert(pcm_service_ != nullptr);

  radio_service_->Init();
  media_service_->Init();
  pcm_service_->Init();
}
