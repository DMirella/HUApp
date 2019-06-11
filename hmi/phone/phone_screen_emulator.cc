#include "phone_screen_emulator.h"
#include "ui_phone_screen_emulator.h"

#include "main/lib_manager.h"
#include "conn/pcmlib.h"

PhoneScreenEmulator::PhoneScreenEmulator(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::PhoneScreenEmulator)
{
  ui->setupUi(this);
}

PhoneScreenEmulator::~PhoneScreenEmulator()
{
  delete ui;
}

void PhoneScreenEmulator::on_pushButton_2_clicked()
{
  if (is_media_plays_) {
    ui->pushButton_2->setText("Play media");
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhoneMediaStop();
  } else {
    ui->pushButton_2->setText("Stop media");
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhoneMediaStart();
  }
  is_media_plays_ = !is_media_plays_;
}

void PhoneScreenEmulator::on_pushButton_clicked()
{
  if (is_navigation_plays_) {
    ui->pushButton->setText("Play navigation");
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhoneNavigationStart();
  } else {
    ui->pushButton->setText("Stop navigation");
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhoneNavigationStop();
  }
  is_navigation_plays_ = !is_navigation_plays_;
}

void PhoneScreenEmulator::on_pushButton_3_clicked()
{
  if (is_phonecall_active_) {
    ui->pushButton_3->setText("Make phonecall");
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhonecallStart();
  } else {
    ui->pushButton_3->setText("Stop phonecall");
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhonecallStop();
  }
  is_phonecall_active_ = !is_phonecall_active_;
}
