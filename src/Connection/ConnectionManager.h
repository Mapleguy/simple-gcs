#pragma once

#ifndef MEDUSAMANAGER_H
#define MEDUSAMANAGER_H

#include <QObject>

class VehicleConnection;

class ConnectionManager : public QObject{
    Q_OBJECT
private:
    QString _address;
    uint16_t _port;

    VehicleConnection* _activeConnection;

public:
    ConnectionManager();

    QString Address() { return _address; }
    uint16_t Port() { return _port; }

private:
    void CreateConnection(int type, QString address, QString port);

public:
    Q_INVOKABLE void connectVehicle(int type, QString address, QString port);
    Q_INVOKABLE void disconnectVehicle();
};

#endif // MEDUSAMANAGER_H
