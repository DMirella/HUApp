#include "main_window.h"
#include "ui_main_window.h"

namespace hmi {

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::Init()
{
  radio_screen_.Init();
  media_screen_.Init();
  phone_screen_.Init();
}

void MainWindow::on_bRadio_clicked() {
  radio_screen_.show();
}

void hmi::MainWindow::on_bMedia_clicked() {
  media_screen_.show();
}

void hmi::MainWindow::on_bPhone_clicked() {
  phone_screen_.show();
}

void hmi::MainWindow::on_bSettings_clicked() {
  settings_screen_.show();
}

}  // hmi
