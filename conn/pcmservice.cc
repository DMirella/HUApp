#include "pcmservice.h"

#include <vector>
#include <algorithm>

#include <QDebug>

#include "main/service_accessor.h"

namespace {

HMIPCMDeviceInfo ConvertPCMLibInfoToHMIPCMDeviceInfo(const PCMDeviceInfo& info) {
  HMIPCMDeviceInfo result;
  result.device_id = info.device_id;
  result.device_name = info.device_name;
  for (auto it : info.enable_technologies) {
    result.enable_technologies_.push_back(static_cast<HMIPhoneTechology>(it));
  }
  return result;
}

QString ConvertMainSourceToQString(audio::MainAudioSource source) {
  switch (source) {
   case audio::MainAudioSource::SRC_EMPTY:
    return "SRC_EMPTY";
   case audio::MainAudioSource::SRC_MEDIA:
    return "SRC_MEDIA";
   case audio::MainAudioSource::SRC_RADIO:
    return "SRC_RADIO";
   case audio::MainAudioSource::SRC_PHONE_MEDIA:
    return "SRC_PHONE_MEDIA";
   case audio::MainAudioSource::SRC_PHONE_PHONECALL:
    return "SRC_PHONE_PHONECALL";
  }
}

QString ConvertAltSourceToQString(audio::AltAudioSource source) {
  switch (source) {
   case audio::AltAudioSource::SRC_EMPTY:
    return "SRC_EMPTY";
   case audio::AltAudioSource::SRC_PHONE_NAVI:
    return "SRC_PHONE_NAVI";
  }
}

}  // namespace

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
    qDebug() << "PCMService::StopMainAudioSource recieved from AudioSerice for source "
             << ConvertMainSourceToQString(source);
    LibManager::GetInstance().GetPCMLib()->StopPhoneMedia();
  }
}

void PCMService::StopAltAudioSource(audio::AltAudioSource source)
{
  if (source == audio::AltAudioSource::SRC_PHONE_NAVI) {
    qDebug() << "PCMService::StopAltAudioSource recieved from AudioSerice for source "
             << ConvertAltSourceToQString(source);
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
