#include "media_screen.h"
#include "ui_media_screen.h"

namespace hmi {

MediaScreen::MediaScreen(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MediaScreen) {
  ui->setupUi(this);
}

MediaScreen::~MediaScreen() {
  delete ui;
}

}  // hmi
