#include "media_screen.h"
#include "ui_media_screen.h"

#include <QDebug>

#include "main/service_accessor.h"

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

void MediaScreen::OnBTMediaDeviceDetected(HMIMediaDeviceInfo info)
{
  ui->comboBox->addItem(QString(info.device_name.c_str()));
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


}  // hmi
