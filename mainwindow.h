#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionEvent>
#include "modbusclient.h"
#include "modbusserver.h"
#include "settingswindow.h"
#include "qjoystick.h"
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void showSettingsWindow();

private:
  Ui::MainWindow *ui;

  ModbusServer *myModbusServer;
  ModbusClient *myModbusClient;

  //Windows
  SettingsWindow *mySettingsWindow;

  QJoystick *myJoystick;

  QTimer *joypadRefresh;
};

#endif // MAINWINDOW_H
