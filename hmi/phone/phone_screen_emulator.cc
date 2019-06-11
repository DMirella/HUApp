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
  if (!is_phonecall_active_) {
    if (is_media_plays_) {
      ui->pushButton_2->setText("Play media");
      is_media_plays_ = false;
      LibManager::GetInstance().GetPCMLib()->EmulateRequestPhoneMediaStop();
    } else {
      ui->pushButton_2->setText("Stop media");
      is_media_plays_ = true;
      LibManager::GetInstance().GetPCMLib()->EmulateRequestPhoneMediaStart();
    }
  } else {
    ui->pushButton_2->setText("Play media");
    is_media_plays_ = false;
  }
}

void PhoneScreenEmulator::on_pushButton_clicked()
{
  if (is_navigation_plays_) {
    ui->pushButton->setText("Play navigation");
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhoneNavigationStop();
  } else {
    ui->pushButton->setText("Stop navigation");
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhoneNavigationStart();
  }
  is_navigation_plays_ = !is_navigation_plays_;
}

void PhoneScreenEmulator::on_pushButton_3_clicked()
{
  if (is_phonecall_active_) {
    ui->pushButton_3->setText("Make phonecall");
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhonecallStop();
    is_phonecall_active_ = false;
  } else {
    ui->pushButton_2->setText("Play media");
    ui->pushButton_3->setText("End phonecall");
    is_phonecall_active_ = true;
    is_media_plays_ = false;
    LibManager::GetInstance().GetPCMLib()->EmulateRequestPhonecallStart();
  }
}
