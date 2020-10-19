#include "VehicleConnection.h"
#include <QDebug>

VehicleConnection::VehicleConnection() : QObject(nullptr) {

}

void VehicleConnection::DisconnectVehicle(){
    qDebug() << "Default disconnect";
}
