#include "settings_screen.h"
#include "ui_settings_screen.h"

namespace hmi {

SettingsScreen::SettingsScreen(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::SettingsScreen) {
  ui->setupUi(this);
}

SettingsScreen::~SettingsScreen() {
  delete ui;
}

}  // hmi
