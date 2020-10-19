#pragma once

#ifndef VEHICLECONNECTION_H
#define VEHICLECONNECTION_H

#include <QObject>

class VehicleConnection : public QObject{
    Q_OBJECT
private:
    bool _connected;

public:
    VehicleConnection();
    bool Connected() { return _connected; }
    virtual void DisconnectVehicle();
};

#endif // VEHICLECONNECTION_H
