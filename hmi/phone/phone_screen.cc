#include "phone_screen.h"
#include "ui_phone_screen.h"

#include "main/service_accessor.h"
#include "main/lib_manager.h"
#include "conn/pcmlib.h"

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

    QListWidgetItem* item_1 = new QListWidgetItem;
    item_1->setText(QString(kCarPlay.c_str()));
    ui->listWidget_2->addItem(item_1);

    QListWidgetItem* item_2 = new QListWidgetItem;
    item_2->setText(QString(kAndroidAuto.c_str()));
    ui->listWidget_2->addItem(item_2);

    QListWidgetItem* item_3 = new QListWidgetItem;
    item_3->setText(QString(kMirrorLink.c_str()));
    ui->listWidget_2->addItem(item_3);
}

void PhoneScreen::OnPCMDeviceDetected(HMIPCMDeviceInfo info)
{
    ui->comboBox->addItem(QString(info.device_name.c_str()));
    devices_id_map_info_[QString(info.device_name.c_str())] = info;
    device_id_to_device_name_map_[info.device_id] = QString(info.device_name.c_str());
    UpdateTechnologyList(ui->comboBox->currentText());
}

void PhoneScreen::OnPCMDeviceLost(int device_id)
{
  ui->comboBox->removeItem(ui->comboBox->findText(
      device_id_to_device_name_map_[device_id]));
}

void PhoneScreen::showEvent(QShowEvent *event)
{
    pcm_reciever_->OnPhoneScreenShown();
}

void PhoneScreen::on_comboBox_currentIndexChanged(int index)
{
  UpdateTechnologyList(ui->comboBox->currentText());
}

void PhoneScreen::UpdateTechnologyList(QString device_name)
{
  ui->comboBox_2->clear();
  auto current_device_info = devices_id_map_info_[device_name];
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

void PhoneScreen::on_pushButton_clicked()
{
  ConnectRequestPhoneInfo info;
  auto device_info = devices_id_map_info_[ui->comboBox->currentText()];
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

void PhoneScreen::on_pushButton_3_clicked()
{
  std::string device_name = ui->lineEdit->text().toLocal8Bit().constData();
  std::vector<PCMDeviceInfo::Techology> available_device_technologies_list;
  for (auto it : ui->listWidget_2->selectedItems()) {
    if (it->text() == QString(kCarPlay.c_str())) {
      available_device_technologies_list.push_back(PCMDeviceInfo::CarPlay);
    } else if (it->text() == QString(kAndroidAuto.c_str())) {
      available_device_technologies_list.push_back(PCMDeviceInfo::AndroidAuto);
    } else if (it->text() == QString(kMirrorLink.c_str())) {
      available_device_technologies_list.push_back(PCMDeviceInfo::MirrorLink);
    }
  }

  LibManager::GetInstance().GetPCMLib()->EmulateDetectedDevice(
      device_name,
      available_device_technologies_list
  );

  QListWidgetItem* item = new QListWidgetItem;
  item->setText(QString(device_name.c_str()));
  ui->listWidget->addItem(item);
}

void PhoneScreen::on_pushButton_2_clicked()
{
  int index = ui->listWidget->currentRow();
  if (index != -1) {
    QString current_text = ui->listWidget->currentItem()->text();
    LibManager::GetInstance().GetPCMLib()->EmulateLostDevice(
          current_text.toLocal8Bit().constData());

    QListWidgetItem *it = ui->listWidget->takeItem(index);
    delete it;
  }
}

}  // hmi
