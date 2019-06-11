#ifndef PCMSERVICERECIEVER_H
#define PCMSERVICERECIEVER_H

#include <QObject>
#include <string>

enum HMIPhoneTechology {
  CarPlay = 0,
  AndroidAuto,
  MirrorLink
};

struct HMIPCMDeviceInfo {
  int device_id;
  std::string device_name;
  std::vector<HMIPhoneTechology> enable_technologies_;
};

class PCMServiceReciever : public QObject {
    Q_OBJECT
 public:
  PCMServiceReciever() {}
  virtual void OnPCMDeviceDetected(HMIPCMDeviceInfo info) = 0;
  virtual void OnPCMDeviceLost(int device_id) = 0;
};

#endif // PCMSERVICERECIEVER_H
