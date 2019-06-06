#include "hmi_service.h"

namespace hmi {

HMIService::HMIService() {

}

void HMIService::start() {
  main_window_.Init();
  main_window_.show();
}

}  // hmi
