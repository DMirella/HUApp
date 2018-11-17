#include "main_window.h"
#include "ui_mainwindow.h"

namespace hmi {

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

}  // hmi
