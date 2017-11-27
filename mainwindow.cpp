#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QtBluetooth>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->tabWidget->setCurrentIndex(0);
  ui->push_reconnect->setEnabled(false);



  //ui->tabWidget->setStyleSheet("background-color:rgb(180,180,180)");

  ui->pushButton->setStyleSheet("background-color:rgb(255,0,0)");
  ui->pushButton_2->setStyleSheet("background-color:rgb(0,255,0)");
  ui->pushButton_3->setStyleSheet("background-color:rgb(0,0,255)");
  ui->pushButton_4->setStyleSheet("background-color:rgb(255,255,255)");
  ui->pushButton_5->setStyleSheet("background-color:rgb(180,180,180)");
  ui->pushButton_6->setStyleSheet("background-color:rgb(70,70,70)");
  ui->pushButton_7->setStyleSheet("background-color:rgb(255,0,255)");
  ui->pushButton_8->setStyleSheet("background-color:rgb(25,189,255)");
  ui->pushButton_9->setStyleSheet("background-color:rgb(125,89,123)");
  ui->pushButton_10->setStyleSheet("background-color:rgb(0,0,0)");


  ui->push_Test->setVisible(false);
  ui->push_Test_2->setVisible(false);
  ui->push_Test_3->setVisible(false);

  ui->tab_2->setEnabled(false);
  ui->tab_3->setEnabled(false);
  ui->tab_4->setEnabled(false);


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
  ui->push_reconnect->setEnabled(true);

  ui->tab_2->setEnabled(true);
  ui->tab_3->setEnabled(true);
  //ui->tab_4->setEnabled(true);

  ui->tabWidget->setCurrentIndex(1);
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

  _socket->write("1,0,0,0");
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



void MainWindow::on_pushButton_clicked()
{
  _socket->write("1,255,0,0");
}

void MainWindow::on_pushButton_2_clicked()
{
  _socket->write("1,0,255,0");
}

void MainWindow::on_pushButton_3_clicked()
{
  _socket->write("1,0,0,255");
}

void MainWindow::on_pushButton_4_clicked()
{
  _socket->write("1,255,255,255");
}

void MainWindow::on_pushButton_5_clicked()
{
  _socket->write("1,180,180,180");
}

void MainWindow::on_pushButton_6_clicked()
{
  _socket->write("1,70,70,70");
}

void MainWindow::on_pushButton_7_clicked()
{
  _socket->write("1,255,0,255");
}

void MainWindow::on_pushButton_8_clicked()
{
  _socket->write("1,25,189,255");
}

void MainWindow::on_pushButton_9_clicked()
{
  _socket->write("1,125,89,123");
}

void MainWindow::on_push_reconnect_clicked()
{
  static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
 _socket->connectToService(QBluetoothAddress(_device_address), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);

 deviceConnected();
}

void MainWindow::on_pushButton_10_clicked()
{
    _socket->write("1,0,0,0");
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    ui->push_Test->setVisible(checked);
    ui->push_Test_2->setVisible(checked);
    ui->push_Test_3->setVisible(checked);
}
