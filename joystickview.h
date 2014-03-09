#ifndef JOYSTICKVIEW_H
#define JOYSTICKVIEW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QResizeEvent>
class JoystickView : public QWidget
{
  Q_OBJECT
public:
  explicit JoystickView(QWidget *parent = 0);
  ~JoystickView();
signals:

public slots:
  //void setAnalog(quint16);
protected:
  void paintEvent(QPaintEvent *);
  void resizeEvent(QResizeEvent *);
private:
  int unitHeight;
  int unitWidth;
  int horizontalOffset;
  int verticalOffset;
  bool *analogLeftHorizontal;
  bool *analogLeftVertical;
  bool *analogRightHorizontal;
  bool *analogRightVertical;
  void calculateUnits();
  int X(int x);
  int Y(int y);
};

#endif // JOYSTICKVIEW_H
