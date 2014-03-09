#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  mySettingsWindow = new SettingsWindow;
  ui->setupUi(this);
  myModbusServer = new ModbusServer(1502);
  myModbusServer->startListening();
  myModbusClient = new ModbusClient;

  connect(this->myModbusClient,SIGNAL(statusConnectedChanged(bool)),this->mySettingsWindow,SLOT(setStatusDiode(bool)));
  connect(this->mySettingsWindow,SIGNAL(connectToHost(QString,int)),this->myModbusClient,SLOT(connectToModbusServer(QString,int)));
  connect(this->mySettingsWindow,SIGNAL(disconnectFromHost()),this->myModbusClient,SLOT(disconnectFromModbusServer()));
  connect(this->ui->actionSettings,SIGNAL(triggered()),this,SLOT(showSettingsWindow()));

  myJoystick = new QJoystick;
  myJoystick->setJoystick(0);
  joypadRefresh = new QTimer;
  joypadRefresh->start(20);

  connect(myJoystick,SIGNAL(axisChanged(int,qint16)),this->ui->widgetJoypad,SLOT(changeAxisStat(int,qint16)));
  connect(myJoystick,SIGNAL(buttonChanged(int,bool)),this->ui->widgetJoypad,SLOT(changeButtonState(int,bool)));
  connect(joypadRefresh,SIGNAL(timeout()),myJoystick,SLOT(getData()));
}
void MainWindow::showSettingsWindow(){
  mySettingsWindow->show();
}

MainWindow::~MainWindow()
{
  delete ui;
}

