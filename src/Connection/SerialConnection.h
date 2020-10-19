#pragma once

#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include "VehicleConnection.h"

class SerialConnection : public VehicleConnection{
    Q_OBJECT
public:
    SerialConnection(QString address, uint16_t baud);
};

#endif // SERIALCONNECTION_H
