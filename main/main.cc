#include <QApplication>

#include <iostream>

#include "service_accessor.h"
#include "lib_manager.h"
#include "hmi/testwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  ServiceAccessor::GetInstance().Init();
  ServiceAccessor::GetInstance().GetHMIService()->start();
  LibManager::GetInstance().Init();

  return app.exec();
}
