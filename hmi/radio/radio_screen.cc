#include "radio_screen.h"

#include <QString>

#include "ui_radio_screen.h"

#include "main/service_accessor.h"

namespace hmi {

RadioScreen::RadioScreen(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::RadioScreen) {
  ui->setupUi(this);

  hmi_radio_reciever_ = ServiceAccessor::GetInstance().GetRadioService();
}

RadioScreen::~RadioScreen() {
    delete ui;
}

void RadioScreen::on_comboBox_currentIndexChanged(const QString &arg1)
{

}

}  // hmi
