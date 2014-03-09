#include "joystickview.h"

JoystickView::JoystickView(QWidget *parent) :
  QWidget(parent)
{
  analogLeftHorizontal = new bool[5];
  analogLeftVertical = new bool[5];
  analogRightHorizontal = new bool[5];
  analogRightVertical = new bool[5];
  for(int i=0 ; i<5 ; i++){
    analogLeftHorizontal[i]=false;
    analogLeftVertical[i]=false;
    analogRightHorizontal[i]=false;
    analogRightVertical[i]=false;
  }
}
//JoystickView::setAnalog(int value){
//
//}

JoystickView::~JoystickView(){
  delete[] analogLeftHorizontal;
  delete[] analogLeftVertical;
  delete[] analogRightHorizontal;
  delete[] analogRightVertical;
}
