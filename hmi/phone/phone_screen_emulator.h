#ifndef PHONE_SCREEN_EMULATOR_H
#define PHONE_SCREEN_EMULATOR_H

#include <QMainWindow>

namespace Ui {
class PhoneScreenEmulator;
}

class PhoneScreenEmulator : public QMainWindow
{
  Q_OBJECT

public:
  explicit PhoneScreenEmulator(QWidget *parent = nullptr);
  ~PhoneScreenEmulator();

private:
  Ui::PhoneScreenEmulator *ui;
};

#endif // PHONE_SCREEN_EMULATOR_H
