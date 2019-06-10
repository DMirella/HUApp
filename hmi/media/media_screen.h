#ifndef MEDIA_SCREEN_H
#define MEDIA_SCREEN_H

#include <QMainWindow>

#include <memory>
#include <unordered_map>
#include <string>

#include "media/hmi_media_reciever.h"
#include "hmi/media/media_service_reciever.h"

namespace Ui {
class MediaScreen;
}

namespace hmi {

class MediaScreen : public QMainWindow
{
  Q_OBJECT

public:
  explicit MediaScreen(QWidget *parent = nullptr);
  ~MediaScreen();

  void Init();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public slots:
    void OnMediaDeviceDetected(HMIMediaDeviceInfo);
    void OnMediaDeviceLost(int);

private:
  Ui::MediaScreen *ui;

  enum MediaButtonState {
      pause = 0,
      play
  };

  void UpdateMediaButtonState();

  MediaButtonState media_button_state_;

  std::shared_ptr<HMIMediaReciever> reciever_;
  QHash<QString, int> device_map_id_;
  QHash<QString, std::string> medialib_emulator_devices_;
  QHash<int, QString> media_device_name_by_id_map_;

  // QWidget interface
protected:
  void showEvent(QShowEvent *event) override {
    reciever_->onBTMediaScreenShow();
  }
};

}  // hmi

#endif // MEDIA_SCREEN_H
