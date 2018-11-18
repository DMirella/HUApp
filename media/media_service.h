#ifndef MEDIA_SERVICE_H
#define MEDIA_SERVICE_H

namespace media {

class MediaService {
 public:
  MediaService(const MediaService& service) = delete;
  MediaService(MediaService&& service) = delete;
  MediaService& operator=(const MediaService& service) = delete;
  MediaService& operator=(MediaService&& service) = delete;

  MediaService();
  ~MediaService() {}

  void start();
};

}  // media

#endif // MEDIA_SERVICE_H
