#ifndef PHONE_SCREEN_H
#define PHONE_SCREEN_H

#include <QMainWindow>
#include <QString>
#include <QHash>

#include <memory>
#include <unordered_map>

#include "hmi/phone/hmiphonereciever.h"
#include "hmi/phone/pcmservicereciever.h"
#include "hmi/phone/phone_screen_emulator.h"

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
  void OnPCMDeviceLost(int device_id);

private slots:
  void on_comboBox_currentIndexChanged(int index);
  void on_pushButton_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_2_clicked();

private:
  void UpdateTechnologyList(QString device_name);

  Ui::PhoneScreen *ui;

  std::shared_ptr<HMIPhoneReciever> pcm_reciever_;
  QHash<QString, HMIPCMDeviceInfo> devices_id_map_info_;
  QHash<int, QString> device_id_to_device_name_map_;

  PhoneScreenEmulator phone_screen_emulator_;

  // QWidget interface
  void showEvent(QShowEvent *event) override;
};

}  // hmi

#endif // PHONE_SCREEN_H
