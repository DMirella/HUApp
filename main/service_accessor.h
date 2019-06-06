#ifndef SERVICE_ACCESSOR_H
#define SERVICE_ACCESSOR_H

#include <memory>

#include "hmi/hmi_service.h"
#include "media/media_service.h"
#include "radio/radio_service.h"

class ServiceAccessor {
 public:
  ServiceAccessor(const ServiceAccessor& service) = delete;
  ServiceAccessor(ServiceAccessor&& service) = delete;
  ServiceAccessor& operator=(const ServiceAccessor& service) = delete;
  ServiceAccessor& operator=(ServiceAccessor&& service) = delete;

  static ServiceAccessor& GetInstance();
  ~ServiceAccessor() {}

  void Init();

  std::shared_ptr<hmi::HMIService> GetHMIService() const {
    return hmi_service_;
  }

  std::shared_ptr<media::MediaService> GetMediaService() const {
    return media_service_;
  }

  std::shared_ptr<radio::RadioService> GetRadioService() const {
    return radio_service_;
  }
 private:
  ServiceAccessor();

  std::shared_ptr<hmi::HMIService> hmi_service_;
  std::shared_ptr<media::MediaService> media_service_;
  std::shared_ptr<radio::RadioService> radio_service_;
};

#endif // SERVICE_ACCESSOR_H
