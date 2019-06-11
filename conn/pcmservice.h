#ifndef PCMSERVICE_H
#define PCMSERVICE_H

#include <QDebug>

#include "pcmlib.h"
#include "hmi/phone/hmiphonereciever.h"
#include "main/lib_manager.h"

class PCMServiceReciever;
namespace pcm {

class PCMService : public PCMLibReciever
                 , public HMIPhoneReciever {
 public:
  PCMService(const PCMService& service) = delete;
  PCMService(PCMService&& service) = delete;
  PCMService& operator=(const PCMService& service) = delete;
  PCMService& operator=(PCMService&& service) = delete;

  PCMService();
  ~PCMService() {}

  void Init();

 private:

  // HMIPhoneReciever
  void OnPhoneScreenShown() override {}
  void OnConnectPhoneRequest(ConnectRequestPhoneInfo info) override;

  // PCMLibReciever interface
  void OnDeviceDetected(const PCMDeviceInfo &info) override;
  void OnDeviceLost(int device_id) override;

  std::shared_ptr<PCMServiceReciever> hmi_reciever_;
};

}  // namespace radio

#endif // PCMSERVICE_H
