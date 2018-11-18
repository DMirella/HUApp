#ifndef PHONE_SCREEN_H
#define PHONE_SCREEN_H

#include <QMainWindow>

namespace Ui {
class PhoneScreen;
}

namespace hmi {

class PhoneScreen : public QMainWindow
{
  Q_OBJECT

public:
  explicit PhoneScreen(QWidget *parent = nullptr);
  ~PhoneScreen();

private:
  Ui::PhoneScreen *ui;
};

}  // hmi

#endif // PHONE_SCREEN_H
