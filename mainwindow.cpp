#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  mySettingsWindow = new SettingsWindow();

  ui->setupUi(this);
  //myModbusServer = new ModbusServer(1502,this);
  //myModbusServer->startListening();
  myRover = new Rover(this);

  connect(this->myRover,SIGNAL(statusConnectedChanged(bool)),this->mySettingsWindow,SLOT(setStatusDiode(bool)));
  connect(this->mySettingsWindow,SIGNAL(connectToHost(QString,int)),this->myRover,SLOT(connectToModbusServer(QString,int)));
  connect(this->mySettingsWindow,SIGNAL(disconnectFromHost()),this->myRover,SLOT(disconnectFromModbusServer()));
  connect(this->ui->actionSettings,SIGNAL(triggered()),this,SLOT(showSettingsWindow()));

  myJoystick = new QJoystick(this);
  myJoystick->setJoystick(0);
  joypadRefresh = new QTimer(this);
  joypadRefresh->start(20);

  connect(myJoystick,SIGNAL(axisChanged(int,qint16)),this->ui->widgetJoypad,SLOT(changeAxisStat(int,qint16)));
  connect(myJoystick,SIGNAL(buttonChanged(int,bool)),this->ui->widgetJoypad,SLOT(changeButtonState(int,bool)));
  connect(joypadRefresh,SIGNAL(timeout()),myJoystick,SLOT(getData()));

  roverRefresh = new QTimer(this);
  roverRefresh->start(50);

  connect(myJoystick,SIGNAL(axisChanged(int,qint16)),myRover,SLOT(interpretJoypadAxis(int,qint16)));
  connect(roverRefresh,SIGNAL(timeout()),myRover,SLOT(sendRoverData()));
}
void MainWindow::showSettingsWindow(){
  mySettingsWindow->show();
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_pushButton_clicked()
{
  for (u_int8_t i = 0; i < 5; i++){
    this->myRover->setRegister(i,i+5);
  }
  this->myRover->writeMultipleRegisters(0,5);
}
