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

  explicit RadioScreen(QWidget *parent = nullptr);
  ~RadioScreen();

  void Init();


private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

public slots:
  void OnStationDetected(HMIRadioStationInfo info);

private:
  std::shared_ptr<HMIRadioReciever> hmi_radio_reciever_;

  Ui::RadioScreen *ui;

  // QWidget interface
protected:
  void showEvent(QShowEvent* event) override;
};

}  // hmi

#endif // RADIO_SCREEN_H
