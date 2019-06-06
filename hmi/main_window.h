#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "hmi/media/media_screen.h"
#include "hmi/phone/phone_screen.h"
#include "hmi/radio/radio_screen.h"
#include "hmi/settings/settings_screen.h"
#include "hmi/testwindow.h"

namespace Ui {
class MainWindow;
}

namespace hmi {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void Init();


 private slots:
  void on_bRadio_clicked();
  void on_bMedia_clicked();
  void on_bPhone_clicked();

  void on_bSettings_clicked();

 private:

  friend class HMIService;
  Ui::MainWindow *ui;

  RadioScreen radio_screen_;
  MediaScreen media_screen_;
  PhoneScreen phone_screen_;
  SettingsScreen settings_screen_;
};

}  // hmi

#endif // MAIN_WINDOW_H
