#include "rover.h"

Rover::Rover(QObject *parent ) :
  ModbusClient(parent)
{ 

}

void Rover::setRightMotorDirection(quint16 value){
  if(value != MOTOR_FORWARD ||
     value != MOTOR_BACKWARD ||
     value != MOTOR_BREAK ||
     value != MOTOR_IDLE)
    return;
  setRegister(0,value);
  writeMultipleRegisters(0,6);
}

void Rover::setLeftMotorDirection(quint16 value){
  if(value != MOTOR_FORWARD ||
     value != MOTOR_BACKWARD ||
     value != MOTOR_BREAK ||
     value != MOTOR_IDLE)
    return;
  setRegister(1,value);
}

void Rover::setRightMotorSpeed(quint16 value){
  setRegister(2,value);
}

void Rover::setLeftMotorSpeed(quint16 value){
  setRegister(3,value);
}

void Rover::setTurningMotorDirection(quint16 value){
  if(value != MOTOR_RIGHT||
     value != MOTOR_LEFT ||
     value != MOTOR_BREAK)
    return;
  setRegister(4,value);
}
void Rover::sendRoverData(){
  setRegister(5,CONNECTION_INDICATOR);
  writeMultipleRegisters(0,6);
}
void Rover::interpretJoypadData(){

}
