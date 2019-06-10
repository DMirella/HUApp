#include "radio_screen.h"

#include <QString>
#include <QMessageBox>

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
}

void RadioScreen::showEvent(QShowEvent* event)
{
  hmi_radio_reciever_->onRadioScreenShow();
}

void RadioScreen::on_pushButton_clicked()
{
  std::string station_name = ui->lineEdit->text().toLocal8Bit().constData();;
  int station_frequency = ui->lineEdit_2->text().toInt();
  LibManager::GetInstance().GetRadioLib()->EmulateStationDetected(station_name, station_frequency);
}

}  // hmi
