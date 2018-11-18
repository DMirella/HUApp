#include "phone_screen.h"
#include "ui_phone_screen.h"

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

}  // hmi
