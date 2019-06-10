#include "phone_screen.h"
#include "ui_phone_screen.h"

#include "main/service_accessor.h"

#include <QDebug>

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
}

void PhoneScreen::showEvent(QShowEvent *event)
{
    pcm_reciever_->OnPhoneScreenShown();
}

void PhoneScreen::on_comboBox_currentIndexChanged(int index)
{
  qDebug() << "on_comboBox_currentIndexChanged " << index;
    ui->comboBox_2->clear();
    if (index != -1) {
      qDebug() << "on_comboBox_currentIndexChanged " << devices_id_map_info_[index].enable_technologies_.size();
        auto current_device_info = devices_id_map_info_[index];
        for (auto it : current_device_info.enable_technologies_) {
            auto add_technology_to_list = [this](std::string technology_string) {
                ui->comboBox_2->addItem(QString(technology_string.c_str()));
            };

            switch (it) {
             case HMIPhoneTechology::CarPlay:
                add_technology_to_list("CarPlay");
                break;
            case HMIPhoneTechology::MirrorLink:
               add_technology_to_list("MirrorLink");
               break;
            case HMIPhoneTechology::AndroidAuto:
               add_technology_to_list("AndroidAuto");
               break;
            }
        }
    }
}

}  // hmi
