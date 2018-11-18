#include "radio_screen.h"
#include "ui_radio_screen.h"

namespace hmi {

RadioScreen::RadioScreen(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::RadioScreen) {
  ui->setupUi(this);
}

RadioScreen::~RadioScreen() {
  delete ui;
}

}  // hmi
