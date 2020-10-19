#pragma once

#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include "VehicleConnection.h"

class TCPConnection : public VehicleConnection{
    Q_OBJECT
public:
    TCPConnection(QString address, uint16_t port);
};

#endif // TCPCONNECTION_H
