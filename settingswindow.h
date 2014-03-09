#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>

namespace Ui {
  class SettingsWindow;
}

class SettingsWindow : public QWidget
{
  Q_OBJECT

public:
  explicit SettingsWindow(QWidget *parent = 0);
  ~SettingsWindow();

signals:
  void connectToHost(QString ip, int port);
  void disconnectFromHost();

public slots:
  void setStatusDiode(bool status);
  void connectButtonPressed();
  void disconnectButtonPressed();
private:

  Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
