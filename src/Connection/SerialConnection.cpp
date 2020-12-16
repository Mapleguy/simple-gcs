#include "SerialConnection.h"
#include "src/Mavlink/mavlinkhandler.h"
#include <QDebug>
#include <QSerialPort>

SerialConnection::SerialConnection(QString address, uint16_t baud) {
    qDebug() << "Created Serial Connection";
    _serial = new QSerialPort();
    _serial->setPortName(address);
    _serial->setBaudRate(baud);
    if(!_serial->open(QIODevice::ReadWrite)){
        qDebug() << "Could not open serial!";
    }else{
        qDebug() << "Opened Serial";
        QObject::connect(_serial, &QIODevice::readyRead, this, &SerialConnection::ReadSerial);

        //TEST FOR REQUESTING PARAMS
        QByteArray pRequest = RequestParameters();
        WriteSerial(pRequest);
    }
}

void SerialConnection::ReadSerial(){
    if (_serial && _serial->isOpen()) {
        qint64 bytes = _serial->bytesAvailable();
        if (bytes) {
            QByteArray buffer;
            buffer.resize(bytes);
            _serial->read(buffer.data(), buffer.size());
            Ingest(buffer);
        }
    } else {
        qDebug() << "Serial port not readable";
    }
}

void SerialConnection::WriteSerial(QByteArray bytes){
    if (_serial && _serial->isOpen()) {
        _serial->write(bytes);
    } else {
        qDebug() << "Serial port not writeable";
    }
}

void SerialConnection::DisconnectVehicle(){
    _serial->close();
    _serial->deleteLater();
    _serial = nullptr;
    qDebug() << "Disconnecting Serial";
}
