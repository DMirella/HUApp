#include "radio_service.h"

#include "hmi/radio/radio_service_reciever.h"
#include "main/service_accessor.h"
#include "audio/audio_sources.h"

#include <QDebug>
#include <QString>

namespace  {

HMIRadioStationInfo ConvertRadioLibInfoToHMIRadioInfo(const RadioStationInfo& info) {
  HMIRadioStationInfo result;
  result.station_id = info.station_id;
  result.station_name = info.station_name;
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

namespace radio {

RadioService::RadioService() {
}

void RadioService::Init()
{
  radio_service_reciever_ = ServiceAccessor::GetInstance().GetHMIService();
}

void RadioService::OnStationDetected(RadioStationInfo info)
{
  radio_service_reciever_->OnStationDetected(ConvertRadioLibInfoToHMIRadioInfo(info));
}

void RadioService::OnStationLost(int station_id)
{
  radio_service_reciever_->OnStationLost(station_id);
}

void RadioService::onStationChanged(int station_id)
{
  ServiceAccessor::GetInstance().GetAudioService()->RequestPlayMainAudioSource(
        audio::MainAudioSource::SRC_RADIO);
  LibManager::GetInstance().GetRadioLib()->PlayRadioStation(station_id);
}

void RadioService::StopMainAudioSource(audio::MainAudioSource source)
{
  if (source == audio::MainAudioSource::SRC_RADIO) {
    qDebug() << "RadioService::StopMainAudioSource recieved from AudioSerice for source "
             << ConvertMainSourceToQString(source);
    LibManager::GetInstance().GetRadioLib()->StopCurrentRadioStation();
  }
}

}  // namespace radio
