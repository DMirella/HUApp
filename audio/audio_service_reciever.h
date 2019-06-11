#ifndef AUDIO_SERVICE_RECIEVER_H
#define AUDIO_SERVICE_RECIEVER_H

#include "audio/audio_service.h"

namespace audio {

class AudioServiceReciever {
 public:
  AudioServiceReciever() {}
  virtual void StopMainAudioSource(MainAudioSource source) {}
  virtual void StopAltAudioSource(AltAudioSource source) {}
};

}  // namespace audio

#endif // AUDIO_SERVICE_RECIEVER_H
