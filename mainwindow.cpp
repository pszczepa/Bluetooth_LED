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

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
  _found_devices.push_back(device);
  ui->listWidget->addItem(device.name());
}

void MainWindow::deviceConnected()
{
  ui->label->setText("Connected :)");
  ui->push_connect->setEnabled(false);
  ui->listWidget->setEnabled(false);
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
  _device_name = item->text();
}

void MainWindow::on_push_Test_clicked()
{
  _socket->write("1,255,0,0");
}

void MainWindow::on_push_Test_2_clicked()
{
  _socket->write("1,0,0,255");
}

void MainWindow::on_push_Test_3_clicked()
{
  //BT_Message test_message_white(1,255,0,123);
  BT_Message test;

  _socket->write(test.ReturnMessage());
}


void MainWindow::on_push_connect_clicked()
{
  QString temp_name;
  QBluetoothDeviceInfo temp_device;

  temp_device = _found_devices.back();

  while(temp_device.name() != _device_name)
    {
      _found_devices.pop_back();
      temp_device = _found_devices.back();
    }

   _device_address = temp_device.address().toString();

   static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
  _socket->connectToService(QBluetoothAddress(_device_address), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);

  deviceConnected();

}


void MainWindow::on_pushButton_9_clicked()
{

}
