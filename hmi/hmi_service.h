#ifndef HMI_SERVICE_H
#define HMI_SERVICE_H

#include "main_window.h"

#include "hmi/radio/radio_screen.h"
#include "radio/hmi_radio_reciever.h"

namespace hmi {

class HMIService {
 public:
  HMIService(const HMIService& service) = delete;
  HMIService(HMIService&& service) = delete;
  HMIService& operator=(const HMIService& service) = delete;
  HMIService& operator=(HMIService&& service) = delete;

  HMIService();
  ~HMIService() {}

  void start();

  std::shared_ptr<RadioServiceReciever> GetRadioServiceReciever() {
    return std::make_shared<RadioServiceReciever>(main_window_.radio_screen_);
  }

 private:
  MainWindow main_window_;
};

}  // hmi

#endif // HMI_SERVICE_H
