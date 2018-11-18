#ifndef RADIO_SERVICE_H
#define RADIO_SERVICE_H


class RadioService {
 public:
  RadioService(const RadioService& service) = delete;
  RadioService(RadioService&& service) = delete;
  RadioService& operator=(const RadioService& service) = delete;
  RadioService& operator=(RadioService&& service) = delete;

  RadioService();
  ~RadioService() {}
};

#endif // RADIO_SERVICE_H
