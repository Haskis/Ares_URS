#include "manipulator.h"

Manipulator::Manipulator(QObject *parent) :
  ModbusClient(parent)
{

}
void Manipulator::sendRoverData(){

}

void Manipulator::interpretJoypadButton(int id, bool status){

}

void Manipulator::interpretJoypadAxis(int id, qint16 value){

}
