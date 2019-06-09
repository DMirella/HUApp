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
    qDebug() << "PhoneScreen: OnPCMDeviceDetected";
    ui->comboBox->addItem(QString(info.device_name.c_str()));
}

void PhoneScreen::showEvent(QShowEvent *event)
{
    qDebug() << "PhoneScreen: Init";
    pcm_reciever_->OnPhoneScreenShown();
    qDebug() << "PhoneScreen: Init";
}

}  // hmi
