#ifndef HMI_SERVICE_H
#define HMI_SERVICE_H

#include "main_window.h"

namespace hmi {

class HMIService {
 public:
  HMIService(const HMIService& service) = delete;
  HMIService(HMIService&& service) = delete;
  HMIService operator=(const HMIService& service) = delete;
  HMIService operator=(HMIService&& service) = delete;

  HMIService();
  ~HMIService() {}

  void start();
 private:
  MainWindow main_window_;
};

}  // hmi

#endif // HMI_SERVICE_H
