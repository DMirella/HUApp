#ifndef AUDIOSOURCES_H
#define AUDIOSOURCES_H

namespace audio {

enum class MainAudioSource {
  SRC_RADIO = 0,
  SRC_MEDIA,
  SRC_PHONE_MEDIA,
  SRC_PHONE_PHONECALL
};

enum class AltAudioSource {
  SRC_PHONE_NAVI = 0
};

}

#endif // AUDIOSOURCES_H
