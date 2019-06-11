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

private slots:
  void on_pushButton_2_clicked();

  void on_pushButton_clicked();

  void on_pushButton_3_clicked();

private:
  Ui::PhoneScreenEmulator *ui;

  bool is_media_plays_ = false;
  bool is_phonecall_active_ = false;
  bool is_navigation_plays_ = false;
};

#endif // PHONE_SCREEN_EMULATOR_H
