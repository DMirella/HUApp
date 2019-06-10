#include "media_screen.h"
#include "ui_media_screen.h"

#include <QDebug>

#include "main/service_accessor.h"
#include "main/lib_manager.h"

namespace hmi {

MediaScreen::MediaScreen(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MediaScreen) {
  ui->setupUi(this);
}

MediaScreen::~MediaScreen() {
    delete ui;
}

void MediaScreen::Init()
{
    media_button_state_ = MediaButtonState::play;
    reciever_ = ServiceAccessor::GetInstance().GetMediaService();
}

void MediaScreen::on_pushButton_clicked()
{
  if (media_button_state_ == MediaButtonState::play) {
    QString current_text = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
    reciever_->onPlayButton(device_map_id_[current_text]);
  } else {
    QString current_text = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
    reciever_->onPauseButton(device_map_id_[current_text]);
  }
  UpdateMediaButtonState();
}

void MediaScreen::OnMediaDeviceDetected(HMIMediaDeviceInfo info)
{
  ui->comboBox->addItem(QString(info.device_name.c_str()));
  media_device_name_by_id_map_[info.device_id] = QString(info.device_name.c_str());
}

void MediaScreen::OnMediaDeviceLost(int device_id)
{
  ui->comboBox->removeItem(ui->comboBox->findText(
                             media_device_name_by_id_map_[device_id]));
}

void MediaScreen::UpdateMediaButtonState()
{
    if (media_button_state_ == MediaButtonState::play) {
        ui->pushButton->setText("Pause");
        media_button_state_ = MediaButtonState::pause;
    } else {
        ui->pushButton->setText("Play");
        media_button_state_ = MediaButtonState::play;
    }
}

void MediaScreen::on_pushButton_2_clicked()
{
  std::string device_name = ui->lineEdit->text().toLocal8Bit().constData();
  std::string device_mac_adress = ui->lineEdit_2->text().toLocal8Bit().constData();
  std::string device_song_name = ui->lineEdit_3->text().toLocal8Bit().constData();
  LibManager::GetInstance().GetBTMediaLib()->EmulateDeviceDetected(
        device_mac_adress,
        device_name,
        device_song_name);

  medialib_emulator_devices_[QString(device_name.c_str())] = device_mac_adress;

  QListWidgetItem* item = new QListWidgetItem;
  item->setText(QString(device_name.c_str()));
  ui->listWidget->addItem(item);
}

void MediaScreen::on_pushButton_3_clicked()
{
  int index = ui->listWidget->currentRow();
  if (index != -1) {
    QString current_text = ui->listWidget->currentItem()->text();
    LibManager::GetInstance().GetBTMediaLib()->EmulateDeviceLost(
        medialib_emulator_devices_[current_text]);

    QListWidgetItem *it = ui->listWidget->takeItem(index);
    delete it;
    medialib_emulator_devices_.erase(medialib_emulator_devices_.find(current_text));
  }
}

}  // hmi
