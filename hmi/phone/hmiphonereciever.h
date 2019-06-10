#ifndef HMIPHONERECIEVER_H
#define HMIPHONERECIEVER_H

struct ConnectRequestPhoneInfo {
  enum Technology {
    CarPlay = 0,
    AndroidAuto,
    MirrorLink
  };

  int device_id;
  Technology technology;
};

class HMIPhoneReciever {
 public:
  virtual void OnPhoneScreenShown() {}
  virtual void OnConnectPhoneRequest(ConnectRequestPhoneInfo info) {}
};

#endif // HMIPHONERECIEVER_H
