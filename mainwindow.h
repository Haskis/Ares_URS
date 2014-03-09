#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionEvent>
#include "modbusclient.h"
#include "modbusserver.h"
#include "settingswindow.h"
#include "qjoystick.h"
#include "rover.h"
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

  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;

  Rover *myRover;
  //ModbusClient *myModbusClient;

  //Windows
  SettingsWindow *mySettingsWindow;

  QJoystick *myJoystick;

  QTimer *joypadRefresh;
  QTimer *roverRefresh;
};

#endif // MAINWINDOW_H
