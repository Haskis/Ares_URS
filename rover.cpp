#include "rover.h"

Rover::Rover(QObject *parent ) :
  ModbusClient(parent)
{ 
}

void Rover::setRightMotorDirection(quint16 value){
  if(value == MOTOR_FORWARD ||
     value == MOTOR_BACKWARD ||
     value == MOTOR_BREAK ||
     value == MOTOR_IDLE)
    setRegister(0,value);
}

void Rover::setLeftMotorDirection(quint16 value){
  if(value == MOTOR_FORWARD ||
     value == MOTOR_BACKWARD ||
     value == MOTOR_BREAK ||
     value == MOTOR_IDLE)
    setRegister(1,value);
}

void Rover::setRightMotorSpeed(quint16 value){
  setRegister(2,value);
}

void Rover::setLeftMotorSpeed(quint16 value){
  setRegister(3,value);
}

void Rover::setTurningMotorDirection(quint16 value){
  if(value == MOTOR_RIGHT||
     value == MOTOR_LEFT ||
     value == MOTOR_BREAK)
  setRegister(4,value);
}
void Rover::sendRoverData(){
  quint16 value;
  getRegister(3,value);
  qDebug()<<value;
  setRegister(5,CONNECTION_INDICATOR);
  writeMultipleRegisters(0,6);
}
void Rover::interpretJoypadButton(int id, bool status){

}

//Set speed and direction of each engine
void Rover::interpretJoypadAxis(int id, qint16 value){

  if(id==1 && value<0){
    if(value=std::numeric_limits<qint16>::min())
      value=std::numeric_limits<qint16>::max();
    setLeftMotorSpeed(qAbs(value));
    setLeftMotorDirection(MOTOR_FORWARD);
  }
  if(id==1 && value>0){
    setLeftMotorSpeed(qAbs(value));
    setLeftMotorDirection(MOTOR_BACKWARD);
  }
  if(id==1 && value==0){
    setLeftMotorSpeed(qAbs(value));
    setLeftMotorDirection(MOTOR_IDLE);
  }

  if(id==3 && value<0){
    if(value=std::numeric_limits<qint16>::min())
      value=std::numeric_limits<qint16>::max();
    setRightMotorSpeed(qAbs(value));
    setRightMotorDirection(MOTOR_FORWARD);
  }
  if(id==3 && value>0){
    setRightMotorSpeed(qAbs(value));
    setRightMotorDirection(MOTOR_BACKWARD);
  }
  if(id==3 && value==0){
    setRightMotorSpeed(qAbs(value));
    setRightMotorDirection(MOTOR_IDLE);
  }
}
