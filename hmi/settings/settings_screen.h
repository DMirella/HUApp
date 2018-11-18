#ifndef SETTINGS_SCREEN_H
#define SETTINGS_SCREEN_H

#include <QMainWindow>

namespace Ui {
class SettingsScreen;
}

namespace hmi {

class SettingsScreen : public QMainWindow
{
  Q_OBJECT

public:
  explicit SettingsScreen(QWidget *parent = nullptr);
  ~SettingsScreen();

private:
  Ui::SettingsScreen *ui;
};

}  // hmi

#endif // SETTINGS_SCREEN_H
