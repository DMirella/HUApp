#include <QApplication>

#include "service_accessor.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  ServiceAccessor::GetInstance().GetHMIService()->start();

  return app.exec();
}
