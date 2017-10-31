#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QListWidget>

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
  void on_push_find_clicked();

  void deviceDiscovered(const QBluetoothDeviceInfo &device);

  void on_listWidget_itemClicked(QListWidgetItem *item);

  void on_push_Test_clicked();

  void on_push_Test_2_clicked();

private:
  Ui::MainWindow *ui;

  QBluetoothDeviceDiscoveryAgent *_agent = new QBluetoothDeviceDiscoveryAgent;
  QBluetoothSocket *_socket;

  QString _device_address;
};

#endif // MAINWINDOW_HH
