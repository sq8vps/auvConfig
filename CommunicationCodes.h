#ifndef COMMUNICATIONCODES_H
#define COMMUNICATIONCODES_H

enum Command
{
    /* simple heartbeat for both sides */
    HEARTBEAT = 0,

    /* emergency commands */
    EMERGENCY_STOP_ALL_THRUSTERS = 1,
    EMERGENCY_STOP_SENDING_DATA,

    /* messages where the response is required*/
    RESPREQ_SEND_BACK_HEALTH_CHECK = 20,

    /* messages which are respones by themselves */
    RESP_HEALTH_CHECK = 60,

    /* messages where the response is not required */
    NORESPREQ_START_SENDING_SENSOR_VALUES = 100
};

#endif
