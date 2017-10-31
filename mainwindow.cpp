#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QtBluetooth>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  connect(_agent, SIGNAL(deviceDiscovered(const QBluetoothDeviceInfo &)), this, SLOT(deviceDiscovered(const QBluetoothDeviceInfo &)));

  _agent->start();


  _socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
  _socket->write("1,255,0,0");
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_push_find_clicked()
{
   ui->listWidget->clear();
  _agent->stop();
  _agent->start();
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
  ui->listWidget->addItem(device.address().toString());
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
  _device_address = item->text();
  item->setText(_device_address);
  ui->listWidget->addItem(_device_address);

  static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
  _socket->connectToService(QBluetoothAddress(_device_address), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);


}

void MainWindow::on_push_Test_clicked()
{
    _socket->write("1,255,0,0");
}




void MainWindow::on_push_Test_2_clicked()
{
     _socket->write("1,0,0,255");

}
