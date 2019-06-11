#ifndef AUDIO_SERVICE_H
#define AUDIO_SERVICE_H

#include <memory>
#include <vector>

#include <QDebug>

#include "audio/audio_sources.h"

namespace audio {

class AudioServiceReciever;

class AudioService {
 public:
  AudioService(const AudioService& service) = delete;
  AudioService(AudioService&& service) = delete;
  AudioService& operator=(const AudioService& service) = delete;
  AudioService& operator=(AudioService&& service) = delete;

  AudioService();
  ~AudioService() {}

  void Init();

  void RequestPlayMainAudioSource(MainAudioSource source) {
    qDebug() << "AudioService::RequestPlayMainAudioSource";
  }

  void RequestPlayAltAudioSource(AltAudioSource source) {
    qDebug() << "AudioService::RequestPlayAltAudioSource";
  }

  void RequestStopMainAudioSource(MainAudioSource source) {
    qDebug() << "AudioService::RequestStopMainAudioSource";
  }

  void RequestStopAltAudioSource(AltAudioSource source) {
    qDebug() << "AudioService::RequestStopAltAudioSource";
  }
 private:
  MainAudioSource main_audio_source_;
  AltAudioSource alt_audio_source_;

  std::vector<std::shared_ptr<AudioServiceReciever> > recievers_list_;
};

}  // namespace audio

#endif // AUDIO_SERVICE_H
