#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QListWidget>
#include <QSwipeGesture>
#include <QGesture>

#include "bt_message.hh"

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
  void deviceDiscovered(const QBluetoothDeviceInfo &device);

  void deviceConnected();

  void on_listWidget_itemClicked(QListWidgetItem *item);

  void on_push_Test_clicked();

  void on_push_Test_2_clicked();

  void on_push_Test_3_clicked();

  void on_push_connect_clicked();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_push_reconnect_clicked();

  void on_pushButton_10_clicked();

  void on_checkBox_toggled(bool checked);


private:
  Ui::MainWindow *ui;

  QBluetoothDeviceDiscoveryAgent *_agent = new QBluetoothDeviceDiscoveryAgent;
  QBluetoothSocket *_socket;

  QString _device_address;
  QString _device_name;

  std::vector<QBluetoothDeviceInfo> _found_devices;
};

#endif // MAINWINDOW_HH
