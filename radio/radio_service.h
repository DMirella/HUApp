#ifndef RADIO_SERVICE_H
#define RADIO_SERVICE_H

#include "radiolib.h"

namespace radio {

class RadioService : public RadioLibReciever {
 public:
  RadioService(const RadioService& service) = delete;
  RadioService(RadioService&& service) = delete;
  RadioService& operator=(const RadioService& service) = delete;
  RadioService& operator=(RadioService&& service) = delete;

  RadioService();
  ~RadioService() {}
};

}  // namespace radio

#endif // RADIO_SERVICE_H
