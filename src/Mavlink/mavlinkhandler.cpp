#include "mavlinkhandler.h"
#include "libs/mavlink/ardupilotmega/mavlink.h"
#include <QDebug>
#include <QByteArray>

//Handle messages in numerical order
//Not including deprecated or WIP messages as per https://mavlink.io/en/messages/common.html
void HandleMavlink(mavlink_message_t msg){
    switch(msg.msgid){
        case MAVLINK_MSG_ID_SYS_STATUS:
            break;

        case MAVLINK_MSG_ID_SYSTEM_TIME:
            break;

        case MAVLINK_MSG_ID_PARAM_REQUEST_READ:
            break;

        case MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST:
            break;

        case MAVLINK_MSG_ID_ATTITUDE:
            break;

        case MAVLINK_MSG_ID_HEARTBEAT:
            mavlink_heartbeat_t hb;
            mavlink_msg_heartbeat_decode(&msg, &hb);
            qDebug() << "Got heartbeat from vehicle: " << msg.sysid;
            break;

        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
            break;

        default:
            break;
    }
}


void Ingest(QByteArray data){
    for(int i = 0; i < data.size(); i++){
        mavlink_message_t msg;
        mavlink_status_t status;
        if(mavlink_parse_char(0, static_cast<uint8_t>(data[i]), &msg, &status)){
            HandleMavlink(msg);
        }
    }
}
