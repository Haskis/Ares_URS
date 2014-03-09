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
}
void MainWindow::showSettingsWindow(){
  mySettingsWindow->show();
}

MainWindow::~MainWindow()
{
  delete ui;
}

