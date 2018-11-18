#ifndef RADIO_SCREEN_H
#define RADIO_SCREEN_H

#include <QMainWindow>

namespace Ui {
class RadioScreen;
}

namespace hmi {

class RadioScreen : public QMainWindow
{
  Q_OBJECT

public:
  explicit RadioScreen(QWidget *parent = nullptr);
  ~RadioScreen();

private:
  Ui::RadioScreen *ui;
};

}  // hmi

#endif // RADIO_SCREEN_H
