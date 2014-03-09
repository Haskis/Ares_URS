#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SettingsWindow)
{
  ui->setupUi(this);
  connect(this->ui->pushButtonConnect,SIGNAL(clicked()),this,SLOT(connectButtonPressed()));
  connect(this->ui->pushButtonDisconnect,SIGNAL(clicked()),this,SLOT(disconnectButtonPressed()));
}

SettingsWindow::~SettingsWindow()
{
  delete ui;
}
void SettingsWindow::setStatusDiode(bool status){
  this->ui->statusDiodeWidget->setStatus(status);
}
void SettingsWindow::connectButtonPressed(){
  emit connectToHost(this->ui->lineEditIP->text(),this->ui->lineEditPort->text().toInt());
}
void SettingsWindow::disconnectButtonPressed(){
  emit disconnectFromHost();
}
