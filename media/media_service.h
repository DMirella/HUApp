#ifndef MEDIA_SERVICE_H
#define MEDIA_SERVICE_H

#include <QDebug>

#include "btmedialib.h"
#include "hmi_media_reciever.h"
#include "hmi/media/media_service_reciever.h"
#include "main/lib_manager.h"

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

  void Init();
 private:
  // BTMediaLibReciever
  void OnDeviceDetected(const BTMediaDeviceInfo& info) override;

  // HMIMediaReciever
  void onPlayButton(int device_id) override {
      qDebug() << "playbtn media pressed\n";
  }

  void onPauseButton(int device_id) override {
      qDebug() << "pausebtn media pressed\n";
  }

  void onBTMediaScreenShow() override {
      LibManager::GetInstance().GetBTMediaLib()->TempTest();
  }

  std::shared_ptr<MediaServiceReciever> reciever_;
};

}  // media

#endif // MEDIA_SERVICE_H
