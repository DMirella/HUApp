#ifndef PHONE_SCREEN_H
#define PHONE_SCREEN_H

#include <QMainWindow>
#include <QString>
#include <QHash>

#include <memory>
#include <unordered_map>

#include "hmi/phone/hmiphonereciever.h"
#include "hmi/phone/pcmservicereciever.h"

namespace Ui {
class PhoneScreen;
}

namespace hmi {

class PhoneScreen : public QMainWindow {
  Q_OBJECT

 public:
  explicit PhoneScreen(QWidget *parent = nullptr);
  ~PhoneScreen();

  void Init();

 public slots:
  void OnPCMDeviceDetected(HMIPCMDeviceInfo info);

private slots:
  void on_comboBox_currentIndexChanged(int index);

  void on_pushButton_clicked();

private:
  void UpdateTechnologyList(int index);

  Ui::PhoneScreen *ui;

  std::shared_ptr<HMIPhoneReciever> pcm_reciever_;
  std::unordered_map<int, HMIPCMDeviceInfo> devices_id_map_info_;

  // QWidget interface
  void showEvent(QShowEvent *event) override;
};

}  // hmi

#endif // PHONE_SCREEN_H
