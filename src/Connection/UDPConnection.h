#pragma once

#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H

#include "VehicleConnection.h"

class QUdpSocket;

class UDPConnection : public VehicleConnection{
    Q_OBJECT
private:
    QUdpSocket* socket;

private:
    void ReadDGram();

public:
    UDPConnection(QString address, uint16_t port);
    void DisconnectVehicle() override;
};

#endif // UDPCONNECTION_H
