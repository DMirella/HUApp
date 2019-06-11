#include "media_service.h"

#include "btmedialib.h"
#include "hmi/media/media_service_reciever.h"
#include "main/service_accessor.h"
#include "audio/audio_sources.h"

namespace  {

HMIMediaDeviceInfo ConvertBTMediaLibInfoToHMIMediaDeviceInfo(const BTMediaDeviceInfo& info) {
  HMIMediaDeviceInfo result;
  result.device_id = info.device_id;
  result.device_name = info.device_name;
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

namespace media {

MediaService::MediaService()
{

}

void MediaService::Init()
{
  reciever_ = ServiceAccessor::GetInstance().GetHMIService();
}

void MediaService::OnDeviceDetected(const BTMediaDeviceInfo &info)
{
  reciever_->OnMediaDeviceDetected(ConvertBTMediaLibInfoToHMIMediaDeviceInfo(info));
}

void MediaService::OnDeviceLost(int device_id)
{
  reciever_->OnMediaDeviceLost(device_id);
}

void MediaService::onPlayButton(int device_id)
{
  ServiceAccessor::GetInstance().GetAudioService()->RequestPlayMainAudioSource(
        audio::MainAudioSource::SRC_MEDIA);
  LibManager::GetInstance().GetBTMediaLib()->PlayBTMedia(device_id);
}

void MediaService::onPauseButton(int device_id)
{
  ServiceAccessor::GetInstance().GetAudioService()->RequestStopMainAudioSource(
        audio::MainAudioSource::SRC_MEDIA);
  LibManager::GetInstance().GetBTMediaLib()->StopBTMedia(device_id);
}

void MediaService::StopMainAudioSource(audio::MainAudioSource source)
{
  if (source == audio::MainAudioSource::SRC_MEDIA) {
    qDebug() << "MediaService::StopMainAudioSource recieved from AudioSerice for source "
             << ConvertMainSourceToQString(source);
    LibManager::GetInstance().GetBTMediaLib()->StopCurrentBTMedia();
  }
}

}  // media
