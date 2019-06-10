#include "phone_screen_emulator.h"
#include "ui_phone_screen_emulator.h"

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
