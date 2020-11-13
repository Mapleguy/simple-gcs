#pragma once

#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include "VehicleConnection.h"

class QSerialPort;

class SerialConnection : public VehicleConnection{
    Q_OBJECT
private:
    QSerialPort* _serial;
public:
    SerialConnection(QString address, uint16_t baud);

private:
    void ReadSerial();

public:
    void DisconnectVehicle() override;
};

#endif // SERIALCONNECTION_H
