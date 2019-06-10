#include "phone_screen.h"
#include "ui_phone_screen.h"

#include "main/service_accessor.h"

#include <QDebug>

namespace  {
const std::string kCarPlay = "CarPlay";
const std::string kAndroidAuto = "AndroidAuto";
const std::string kMirrorLink = "MirrorLink";
}

namespace hmi {

PhoneScreen::PhoneScreen(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::PhoneScreen)
{
  ui->setupUi(this);
}

PhoneScreen::~PhoneScreen()
{
    delete ui;
}

void PhoneScreen::Init()
{
    pcm_reciever_ = ServiceAccessor::GetInstance().GetPCMService();
}

void PhoneScreen::OnPCMDeviceDetected(HMIPCMDeviceInfo info)
{
    ui->comboBox->addItem(QString(info.device_name.c_str()));
    devices_id_map_info_[ui->comboBox->count() - 1] = info;

    UpdateTechnologyList(ui->comboBox->currentIndex());
}

void PhoneScreen::showEvent(QShowEvent *event)
{
    pcm_reciever_->OnPhoneScreenShown();
}

void PhoneScreen::on_comboBox_currentIndexChanged(int index)
{
  UpdateTechnologyList(index);
}

void PhoneScreen::UpdateTechnologyList(int index)
{
  ui->comboBox_2->clear();
  if (index != -1) {
      auto current_device_info = devices_id_map_info_[index];
      for (auto it : current_device_info.enable_technologies_) {
          auto add_technology_to_list = [this](std::string technology_string) {
              ui->comboBox_2->addItem(QString(technology_string.c_str()));
          };

          switch (it) {
           case HMIPhoneTechology::CarPlay:
              add_technology_to_list(kCarPlay);
              break;
          case HMIPhoneTechology::MirrorLink:
             add_technology_to_list(kMirrorLink);
             break;
          case HMIPhoneTechology::AndroidAuto:
             add_technology_to_list(kAndroidAuto);
             break;
          }
      }
  }
}

void PhoneScreen::on_pushButton_clicked()
{
  ConnectRequestPhoneInfo info;
  auto device_info = devices_id_map_info_[ui->comboBox->currentIndex()];
  info.device_id = device_info.device_id;
  if (ui->comboBox_2->currentText() == QString(kCarPlay.c_str())) {
    info.technology = ConnectRequestPhoneInfo::Technology::CarPlay;
  } else if (ui->comboBox_2->currentText() == QString(kAndroidAuto.c_str())) {
    info.technology = ConnectRequestPhoneInfo::Technology::AndroidAuto;
  } else if (ui->comboBox_2->currentText() == QString(kMirrorLink.c_str())) {
    info.technology = ConnectRequestPhoneInfo::Technology::MirrorLink;
  }
  pcm_reciever_->OnConnectPhoneRequest(info);
}

}  // hmi
