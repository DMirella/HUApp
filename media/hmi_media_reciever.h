#ifndef HMI_MEDIA_RECIEVER_H
#define HMI_MEDIA_RECIEVER_H

class HMIMediaReciever {
 public:
  virtual void onBTMediaScreenShow() = 0;
  virtual void onPlayButton(int device_id) = 0;
  virtual void onPauseButton(int device_id) = 0;
};

#endif // HMI_MEDIA_RECIEVER_H
