#ifndef MEDIA_SERVICE_H
#define MEDIA_SERVICE_H

#include "btmedialib.h"

namespace media {

class MediaService : public BTMediaLibReciever {
 public:
  MediaService(const MediaService& service) = delete;
  MediaService(MediaService&& service) = delete;
  MediaService& operator=(const MediaService& service) = delete;
  MediaService& operator=(MediaService&& service) = delete;

  MediaService();
  ~MediaService() {}

  void start();
 private:
  void OnDeviceDetected(const BTMediaDeviceInfo& info) override {

  }

  void OnPlayButton(int device_id) {

  }
};

}  // media

#endif // MEDIA_SERVICE_H
