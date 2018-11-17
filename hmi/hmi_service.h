#ifndef HMI_SERVICE_H
#define HMI_SERVICE_H

#include "main_window.h"

namespace hmi {

class HMIService {
 public:
  HMIService();

  void start();
 private:
  MainWindow main_window_;
};

}  // hmi

#endif // HMI_SERVICE_H
