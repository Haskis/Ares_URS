#include "joystickview.h"

JoystickView::JoystickView(QWidget *parent) :
  QWidget(parent)
{
  calculateUnits();
}
//JoystickView::setAnalog(int value){
//
//}

JoystickView::~JoystickView(){

}
void JoystickView::calculateUnits(){
  unitHeight = height()/9;
  unitWidth = width()/19;

  unitHeight = qMin(unitHeight,unitWidth);
  unitWidth = unitHeight;
  verticalOffset = (height()%9)/2;
  horizontalOffset = (width()%19)/2;
}
int JoystickView::X(int x){
  return horizontalOffset+x*unitWidth;
}

int JoystickView::Y(int y){
  return verticalOffset+y*unitHeight;
}
void JoystickView::resizeEvent(QResizeEvent *){
  calculateUnits();
  repaint();
}

void JoystickView::paintEvent(QPaintEvent *){
  QPainter myPainter;
  myPainter.begin(this);
  myPainter.setBrush(Qt::red);
  myPainter.setPen(Qt::black);
  myPainter.setRenderHints(QPainter::Antialiasing);
  //Analog 1
  myPainter.drawRect(X(0),Y(4),X(4),Y(1));
  myPainter.drawRect(X(5),Y(4),X(4),Y(1));

  myPainter.drawRect(X(4),Y(5),X(1),Y(4));
  myPainter.drawRect(X(4),Y(0),X(1),Y(4));

  //Analog 2
  myPainter.drawRect(X(10),Y(4),X(4),Y(1));
  myPainter.drawRect(X(15),Y(4),X(4),Y(1));

  myPainter.drawRect(X(14),Y(5),X(1),Y(4));
  myPainter.drawRect(X(14),Y(0),X(1),Y(4));
  //Triggers

  myPainter.drawRect(X(6),Y(0),X(3),Y(1));
  myPainter.drawRect(X(6),Y(2),X(3),Y(1));
  myPainter.drawRect(X(10),Y(0),X(3),Y(1));
  myPainter.drawRect(X(10),Y(2),X(3),Y(1));

  //Buttons
  myPainter.drawRect(X(6),Y(7),X(2),Y(1));
  myPainter.drawRect(X(11),Y(7),X(2),Y(1));

  myPainter.drawRect(X(8),Y(6),X(3),Y(1));
  myPainter.drawRect(X(8),Y(8),X(3),Y(1));
}
