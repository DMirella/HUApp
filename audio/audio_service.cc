#include "audio_service.h"

#include "main/service_accessor.h"

namespace audio {

AudioService::AudioService()
{

}

void AudioService::Init()
{
  recievers_list_.push_back(ServiceAccessor::GetInstance().GetPCMService());
  recievers_list_.push_back(ServiceAccessor::GetInstance().GetRadioService());
  recievers_list_.push_back(ServiceAccessor::GetInstance().GetMediaService());
}

}  // namespace audio
