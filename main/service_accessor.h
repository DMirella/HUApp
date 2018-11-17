#ifndef SERVICE_ACCESSOR_H
#define SERVICE_ACCESSOR_H

#include <memory>

#include "hmi/hmi_service.h"

class ServiceAccessor {
 public:
  static ServiceAccessor& GetInstance();
  ~ServiceAccessor() {}

  std::shared_ptr<hmi::HMIService> GetHMIService() const {
    return hmi_service_;
  }
 private:
  ServiceAccessor();

  std::shared_ptr<hmi::HMIService> hmi_service_;
};

#endif // SERVICE_ACCESSOR_H
