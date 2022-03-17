#ifndef COMMUNICATIONCODES_H
#define COMMUNICATIONCODES_H

enum Command
{
    /* payload - one word = uint16_t = 2B */
    /* simple heartbeat for both sides */
    HEARTBEAT = 0, // 1 word payload, OK response

    /* emergency commands */
    EMERGENCY_STOP_ALL_THRUSTERS = 1,
    EMERGENCY_STOP_SENDING_DATA,

    /* messages where the response is required*/
    RESPREQ_SEND_BACK_HEALTH_CHECK = 20,

    /* messages which are respones by themselves */
    RESP_HEALTH_CHECK = 60,    // 1 word payload, short response OK/NOT OK
    RESP_PRECISE_HEALTH_CHECK, // longer payload with codes of hardware devices that are not working

    /* messages where the response is not required */
    NORESPREQ_START_SENDING_SENSOR_VALUES = 100, // no payload
    NORESPREQ_SET_THRUSTERS,                     // 5 words payload of values for thrusters [0,2000]
    NORESPREQ_SET_SERVOS,                        // 2 words payload - first number of servo, second - value [0,100]
    NORESPREQ_SET_AZIMUTHAL_SERVOS,              // 2 words payload - value servo 0, value servo 1 - both [0,100]

    /* orders from devPC */
    DEVPC_SET_THRUSTERS = 245,  // 5 words payload
    DEVPC_SET_SERVOS,           // 2 words payload
    DEVPC_SET_GLOBAL_POSITION,  // 6 word payload
    DEVPC_SET_RELATIVE_POSITION // 6 word payload
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
