#include "pcmservice.h"

#include <vector>
#include <algorithm>

#include <QDebug>

#include "main/service_accessor.h"


HMIPCMDeviceInfo ConvertPCMLibInfoToHMIPCMDeviceInfo(const PCMDeviceInfo& info) {
  HMIPCMDeviceInfo result;
  result.device_id = info.device_id;
  result.device_name = info.device_name;
  for (auto it : info.enable_technologies) {
    result.enable_technologies_.push_back(static_cast<HMIPhoneTechology>(it));
  }
  return result;
}

namespace pcm {

PCMService::PCMService()
{

}

void PCMService::Init()
{
    hmi_reciever_ = ServiceAccessor::GetInstance().GetHMIService();
}

void PCMService::OnDeviceDetected(const PCMDeviceInfo &info)
{
  hmi_reciever_->OnPCMDeviceDetected(ConvertPCMLibInfoToHMIPCMDeviceInfo(info));
}

void PCMService::OnDeviceLost(int device_id)
{
  hmi_reciever_->OnPCMDeviceLost(device_id);
}

void PCMService::OnPhoneMediaStart()
{
  ServiceAccessor::GetInstance().GetAudioService()->RequestPlayMainAudioSource(
      audio::MainAudioSource::SRC_PHONE_MEDIA);
}

void PCMService::OnPhoneMediaStop()
{
  ServiceAccessor::GetInstance().GetAudioService()->RequestStopMainAudioSource(
      audio::MainAudioSource::SRC_PHONE_MEDIA);
}

void PCMService::OnPhonePhonecallStart()
{
  ServiceAccessor::GetInstance().GetAudioService()->RequestPlayMainAudioSource(
      audio::MainAudioSource::SRC_PHONE_PHONECALL);
}

void PCMService::OnPhonePhonecallStop()
{
  ServiceAccessor::GetInstance().GetAudioService()->RequestStopMainAudioSource(
      audio::MainAudioSource::SRC_PHONE_PHONECALL);
}

void PCMService::OnPhoneNavigationStart()
{
  ServiceAccessor::GetInstance().GetAudioService()->RequestPlayAltAudioSource(
      audio::AltAudioSource::SRC_PHONE_NAVI);
}

void PCMService::OnPhoneNavigationStop()
{
  ServiceAccessor::GetInstance().GetAudioService()->RequestStopAltAudioSource(
        audio::AltAudioSource::SRC_PHONE_NAVI);
}

void PCMService::StopMainAudioSource(audio::MainAudioSource source)
{
  if (source == audio::MainAudioSource::SRC_PHONE_MEDIA) {
    qDebug() << "PCMService::StopMainAudioSource requested stop phone media"
             << " from AudioService recieved";
    LibManager::GetInstance().GetPCMLib()->StopPhoneMedia();
  }
}

void PCMService::StopAltAudioSource(audio::AltAudioSource source)
{
  if (source == audio::AltAudioSource::SRC_PHONE_NAVI) {
    qDebug() << "PCMService::StopMainAudioSource requested stop phone navigation"
             << "from AudioService recieved";
    LibManager::GetInstance().GetPCMLib()->StopPhoneNavigation();
  }
}

void PCMService::OnConnectPhoneRequest(ConnectRequestPhoneInfo info)
{
  LibManager::GetInstance().GetPCMLib()->ConnectDevice(
      info.device_id,
      static_cast<PCMDeviceInfo::Techology>(info.technology)
  );
}

}  // namespace pcm
