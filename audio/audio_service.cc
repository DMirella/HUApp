#include "audio_service.h"

#include "main/service_accessor.h"
#include "main/lib_manager.h"
#include "audio/audiolib.h"

#include <QDebug>
#include <QString>

namespace  {

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

}

namespace audio {

AudioService::AudioService()
{

}

void AudioService::Init()
{
  recievers_list_.push_back(ServiceAccessor::GetInstance().GetPCMService());
  recievers_list_.push_back(ServiceAccessor::GetInstance().GetRadioService());
  recievers_list_.push_back(ServiceAccessor::GetInstance().GetMediaService());

  main_audio_source_ = MainAudioSource::SRC_EMPTY;
  alt_audio_source_ = AltAudioSource::SRC_EMPTY;
}

void AudioService::RequestPlayMainAudioSource(MainAudioSource source)
{
  qDebug() << "AudioService::RequestPlayMainAudioSource "
           << ConvertMainSourceToQString(source);
  if (main_audio_source_ != MainAudioSource::SRC_EMPTY &&
      main_audio_source_ != source) {
    for (auto it : recievers_list_) {
      it->StopMainAudioSource(main_audio_source_);
    }
  } else {
    LibManager::GetInstance().GetAudioLib()->OpenPort("main channel defualt port");
  }
  main_audio_source_ = source;
}

void AudioService::RequestStopMainAudioSource(MainAudioSource source)
{
  qDebug() << "AudioService::RequestStopMainAudioSource "
           << ConvertMainSourceToQString(source);
  LibManager::GetInstance().GetAudioLib()->ClosePort("main channel defualt port");
  main_audio_source_ = MainAudioSource::SRC_EMPTY;
}

void AudioService::RequestPlayAltAudioSource(AltAudioSource source)
{
  qDebug() << "AudioService::RequestPlayAltAudioSource "
           << ConvertAltSourceToQString(source);
  if (alt_audio_source_ != AltAudioSource::SRC_EMPTY &&
      alt_audio_source_ != source) {
    for (auto it : recievers_list_) {
      it->StopAltAudioSource(alt_audio_source_);
    }
  } else {
    LibManager::GetInstance().GetAudioLib()->OpenPort("alt channel defualt port");
  }
  alt_audio_source_ = source;
}

void AudioService::RequestStopAltAudioSource(AltAudioSource source)
{
  qDebug() << "AudioService::RequestStopAltAudioSource "
           << ConvertAltSourceToQString(source);
  LibManager::GetInstance().GetAudioLib()->ClosePort("alt channel defualt port");
  alt_audio_source_ = AltAudioSource::SRC_EMPTY;
}

}  // namespace audio
