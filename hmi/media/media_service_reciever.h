#ifndef MEDIA_SERVICE_RECIEVER_H
#define MEDIA_SERVICE_RECIEVER_H

#include <QObject>
#include <string>

struct HMIMediaDeviceInfo {
  int device_id;
  std::string device_name;
};

class MediaServiceReciever : public QObject {
    Q_OBJECT
 public:
  MediaServiceReciever() {}
  virtual void OnMediaDeviceDetected(HMIMediaDeviceInfo info) = 0;
  virtual void OnMediaDeviceLost(int device_id) = 0;
};

#endif // MEDIA_SERVICE_RECIEVER_H
