#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionEvent>
#include "modbusclient.h"
#include "modbusserver.h"
#include "settingswindow.h"
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
};

#endif // MAINWINDOW_H
