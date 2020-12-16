#ifndef MAVLINKHANDLER_H
#define MAVLINKHANDLER_H

class QByteArray;

void Ingest(QByteArray data);
void HandleMavlink();
QByteArray RequestParameters();


#endif // MAVLINKHANDLER_H
