#ifndef RADIO_SCREEN_H
#define RADIO_SCREEN_H

#include <QMainWindow>
#include <memory>

#include "radio_service_reciever.h"
#include "radio/hmi_radio_reciever.h"

namespace Ui {
class RadioScreen;
}

namespace hmi {

class RadioScreen : public QMainWindow {
  Q_OBJECT

public:
  class RadioServiceRecieverDelegate : public RadioServiceReciever {
   public:
      RadioServiceRecieverDelegate()
          : RadioServiceReciever() {}
      void OnStationDetected(HMIRadioStationInfo info) override {}
  };
  explicit RadioScreen(QWidget *parent = nullptr);
  ~RadioScreen();

  std::shared_ptr<RadioServiceRecieverDelegate> GetRadioServiceRecieverDelegate() const  {
      return radio_service_reciever_delegate_;
  }

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

private:

  std::shared_ptr<HMIRadioReciever> hmi_radio_reciever_;
  std::shared_ptr<RadioServiceRecieverDelegate> radio_service_reciever_delegate_;

  Ui::RadioScreen *ui;
};

}  // hmi

#endif // RADIO_SCREEN_H
