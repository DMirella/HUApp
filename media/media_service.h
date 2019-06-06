#ifndef MEDIA_SERVICE_H
#define MEDIA_SERVICE_H

#include "btmedialib.h"
#include "hmi_media_reciever.h"

namespace media {

class MediaService : public BTMediaLibReciever
                   , public HMIMediaReciever {
 public:
  MediaService(const MediaService& service) = delete;
  MediaService(MediaService&& service) = delete;
  MediaService& operator=(const MediaService& service) = delete;
  MediaService& operator=(MediaService&& service) = delete;

  MediaService();
  ~MediaService() {}

  void start();
 private:
  // BTMediaLibReciever
  void OnDeviceDetected(const BTMediaDeviceInfo& info) override {}

  // HMIMediaReciever
  void onPlayButton(int device_id) override {}
};

}  // media

#endif // MEDIA_SERVICE_H
