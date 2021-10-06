#ifndef COMMUNICATIONCODES_H
#define COMMUNICATIONCODES_H

enum Command
{
    /* simple heartbeat for both sides */
    HEARTBEAT = 0, // 1B payload, OK response

    /* emergency commands */
    EMERGENCY_STOP_ALL_THRUSTERS = 1,
    EMERGENCY_STOP_SENDING_DATA,

    /* messages where the response is required*/
    RESPREQ_SEND_BACK_HEALTH_CHECK = 20,

    /* messages which are respones by themselves */
    RESP_HEALTH_CHECK = 60, // payload 1B, short response OK/NOT OK
    RESP_PRECISE_HEALTH_CHECK, // longer payload with codes of hardware devices that are not working

    /* messages where the response is not required */
    NORESPREQ_START_SENDING_SENSOR_VALUES = 100
};

enum ShortPayloads
{
    /* payloads that are for common use*/
    FATAL = 0,
    ALL_OK = 1,
    OK = 1,
};

enum ElectronicHardwareCodes
{
    /* insert the hardware connected to stm that can fail */
    PRESSURE_SENSOR
};
#endif
