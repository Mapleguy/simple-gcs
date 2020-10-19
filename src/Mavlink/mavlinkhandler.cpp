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

        case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL:
            break;

        case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK:
            break;

        case MAVLINK_MSG_ID_AUTH_KEY:
            break;

        case MAVLINK_MSG_ID_PARAM_REQUEST_READ:
            break;

        case MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST:
            break;

        case MAVLINK_MSG_ID_PARAM_VALUE:
            break;

        case MAVLINK_MSG_ID_PARAM_SET:
            break;

        case MAVLINK_MSG_ID_GPS_RAW_INT:
            break;

        case MAVLINK_MSG_ID_GPS_STATUS:
            break;

        case MAVLINK_MSG_ID_SCALED_IMU:
            break;

        case MAVLINK_MSG_ID_RAW_IMU:
            break;

        case MAVLINK_MSG_ID_RAW_PRESSURE:
            break;

        case MAVLINK_MSG_ID_SCALED_PRESSURE:
            break;

        case MAVLINK_MSG_ID_ATTITUDE:
            break;

        case MAVLINK_MSG_ID_ATTITUDE_QUATERNION:
            break;

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
            break;

        case MAVLINK_MSG_ID_HEARTBEAT:
            qDebug() << "Got heartbeat";
            break;

        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
            //qDebug() << "Got gloabl position int";
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
