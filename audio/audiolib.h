#ifndef AUDIOLIB_H
#define AUDIOLIB_H

#include <string>
#include <QString>
#include <QDebug>

class AudioLib {
 public:
  AudioLib() {}
  void OpenPort(std::string port_name) {
    qDebug() << "Port " << QString(port_name.c_str()) << " is opened";
  }

  void ClosePort(std::string port_name) {
    qDebug() << "Port " << QString(port_name.c_str()) << " is closed";
  }
};

#endif // AUDIOLIB_H
