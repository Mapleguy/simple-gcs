#include "ConnectionManager.h"
#include "VehicleConnection.h"
#include <QDebug>

ConnectionManager::ConnectionManager() : QObject(nullptr) {
    qDebug() << "Created Connection Manager";
    _activeConnection = nullptr;
}

void ConnectionManager::connectVehicle(int type, QString address, QString port) {
    if(_activeConnection){
        if(!_activeConnection->Connected()){
            CreateConnection(type, address, port);
        } else {
            qDebug() << "Currently connected to a vehicle! Disconnect before attempting new connection!";
        }
    } else {
        CreateConnection(type, address, port);
    }
}

void ConnectionManager::disconnectVehicle() {
    qDebug() << "Disconnecting from vehicle";
}

void ConnectionManager::CreateConnection(int type, QString address, QString port) {
    switch(type){
        case 0:
            qDebug() << "Connecting to vehicle type UDP at: " + address + ":" + port;
            break;
        case 1:
            qDebug() << "Connecting to vehicle type TCP at: " + address + ":" + port;
            break;
        case 2:
            qDebug() << "Connecting to vehicle type Serial at: " + address + ":" + port;
            break;
        default:
            qDebug() << "ERROR IN CONN TYPE";
            break;
    }
}

