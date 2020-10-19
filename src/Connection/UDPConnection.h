#pragma once

#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H

#include "VehicleConnection.h"

class UDPConnection : public VehicleConnection{
    Q_OBJECT
public:
    UDPConnection(QString address, uint16_t port);
};

#endif // UDPCONNECTION_H
