#include "radio_screen.h"

#include <QString>
#include <QMessageBox>
#include <QListView>
#include <QListWidgetItem>

#include "ui_radio_screen.h"
#include "main/service_accessor.h"
#include "main/lib_manager.h"

#include <iostream>

namespace hmi {

RadioScreen::RadioScreen(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::RadioScreen) {
  ui->setupUi(this);
}

RadioScreen::~RadioScreen() {
  delete ui;
}

void RadioScreen::Init()
{
  hmi_radio_reciever_ = ServiceAccessor::GetInstance().GetRadioService();
}

void RadioScreen::on_comboBox_currentIndexChanged(const QString &arg1)
{

}

void RadioScreen::OnStationDetected(HMIRadioStationInfo info)
{
  ui->comboBox->addItem(QString(info.station_name.c_str()));
  radio_name_by_id_map_[info.station_id] = QString(info.station_name.c_str());
  qDebug() <<  info.station_id << " " <<  QString(info.station_name.c_str());
}

void RadioScreen::OnStationLost(int station_id)
{
  ui->comboBox->removeItem(ui->comboBox->findText(radio_name_by_id_map_[station_id]));
}

void RadioScreen::showEvent(QShowEvent* event)
{
  hmi_radio_reciever_->onRadioScreenShow();
}

void RadioScreen::on_pushButton_clicked()
{
  std::string station_name = ui->lineEdit->text().toLocal8Bit().constData();
  int station_frequency = ui->lineEdit_2->text().toInt();
  LibManager::GetInstance().GetRadioLib()->EmulateStationDetected(station_name, station_frequency);

  radiolib_emulator_stations_[QString(station_name.c_str())] = station_frequency;

  QListWidgetItem* item = new QListWidgetItem;
  item->setText(QString(station_name.c_str()));
  ui->listWidget->addItem(item);
}

void RadioScreen::on_pushButton_2_clicked()
{
  int index = ui->listWidget->currentRow();
  if (index != -1) {
    QString current_text = ui->listWidget->currentItem()->text();
    LibManager::GetInstance().GetRadioLib()->EmulateStationLost(
          radiolib_emulator_stations_[current_text]);

    QListWidgetItem *it = ui->listWidget->takeItem(index);
    delete it;
    radiolib_emulator_stations_.erase(radiolib_emulator_stations_.find(current_text));
  }
}

}  // hmi
