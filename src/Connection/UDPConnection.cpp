#include "UDPConnection.h"
#include <QUdpSocket>
#include <QDebug>

UDPConnection::UDPConnection(QString address, uint16_t port) {
    socket = new QUdpSocket();
    socket->bind(QHostAddress(address), port);
    connect(socket, &QUdpSocket::readyRead, this, &UDPConnection::ReadDGram);
    qDebug() << "Created UDP Connection";
}

void UDPConnection::ReadDGram(){
    while(socket->hasPendingDatagrams()){
        QByteArray buffer;
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        QHostAddress sndAddr;
        quint16 sndPort;

        socket->readDatagram(datagram.data(), datagram.size(), &sndAddr, &sndPort);

        buffer.append(datagram);

        qDebug() << "Read Datagram";
    }
}


void UDPConnection::DisconnectVehicle(){
    socket->close();
    socket->deleteLater();
    socket = nullptr;
    qDebug() << "Disconnecting UDP";
}
