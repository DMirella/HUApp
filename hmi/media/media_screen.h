#ifndef MEDIA_SCREEN_H
#define MEDIA_SCREEN_H

#include <QMainWindow>

namespace Ui {
class MediaScreen;
}

namespace hmi {

class MediaScreen : public QMainWindow
{
  Q_OBJECT

public:
  explicit MediaScreen(QWidget *parent = nullptr);
  ~MediaScreen();

private:
  Ui::MediaScreen *ui;
};

}  // hmi

#endif // MEDIA_SCREEN_H
