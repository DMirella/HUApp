#include "lib_manager.h"
#include "audio/audiolib.h"
#include "main/service_accessor.h"

void LibManager::Init() {
  btmedia_lib_ = std::make_shared<BTMediaLib>(
        ServiceAccessor::GetInstance().GetMediaService());
  radio_lib_ = std::make_shared<RadioLib>(
        ServiceAccessor::GetInstance().GetRadioService());
  pcm_lib_ = std::make_shared<PCMLib>(
        ServiceAccessor::GetInstance().GetPCMService());
  audio_lib_ = std::make_shared<AudioLib>();
}
