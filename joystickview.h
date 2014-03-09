#ifndef JOYSTICKVIEW_H
#define JOYSTICKVIEW_H

#include <QWidget>

class JoystickView : public QWidget
{
  Q_OBJECT
public:
  explicit JoystickView(QWidget *parent = 0);
  ~JoystickView();
signals:

public slots:
  //void setAnalog(quint16);
private:
  bool *analogLeftHorizontal;
  bool *analogLeftVertical;
  bool *analogRightHorizontal;
  bool *analogRightVertical;

};

#endif // JOYSTICKVIEW_H
