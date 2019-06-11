#ifndef AUDIOSOURCES_H
#define AUDIOSOURCES_H

namespace audio {

enum class MainAudioSource {
  SRC_EMPTY = 0,
  SRC_RADIO ,
  SRC_MEDIA,
  SRC_PHONE_MEDIA,
  SRC_PHONE_PHONECALL
};

enum class AltAudioSource {
  SRC_EMPTY = 0,
  SRC_PHONE_NAVI
};

}

#endif // AUDIOSOURCES_H
