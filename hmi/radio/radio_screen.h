#ifndef RADIO_SCREEN_H
#define RADIO_SCREEN_H

#include <QMainWindow>
#include <QHash>
#include <QString>

#include <memory>
#include <unordered_map>

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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public slots:
  void OnStationDetected(HMIRadioStationInfo info);
  void OnStationLost(int station_id);

private:
  std::shared_ptr<HMIRadioReciever> hmi_radio_reciever_;
  QHash<QString, int> radiolib_emulator_stations_;
  QHash<int, QString> radio_name_by_id_map_;

  Ui::RadioScreen *ui;

  // QWidget interface
protected:
  void showEvent(QShowEvent* event) override;
};

}  // hmi

#endif // RADIO_SCREEN_H
