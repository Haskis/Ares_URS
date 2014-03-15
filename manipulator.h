#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "modbusclient.h"

/*How data is organized in HoldingRegisters for Manipulator Unit
 *
 * // DO UZUPELNIENIA
 * 1 - Left Motor Direction
 * 2 - Right Motor Speed
 * 3 - Left Motor Speed
 * 4 - Turning Motor Direction
 * 5 - Connection Indicator
 * 6 -
 */

class Manipulator : public ModbusClient
{
public:
  Manipulator(QObject *parent = 0);

public slots:

  void sendRoverData();

  void interpretJoypadButton(int id, bool status);
  void interpretJoypadAxis(int id, qint16 value);

private slots:

private:


};
#endif // MANIPULATOR_H
