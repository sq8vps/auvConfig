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
    RESPREQ_SET_RATE_OF_PRESSURE_SENSOR_REPORT, // one word payload, rate in Hz
    RESPREQ_GET_PRESSURE_SENSOR_VALUE_ONCE,     // no payload

    /* messages which are respones by themselves */
    RESP_HEALTH_CHECK = 60,                  // 1 word payload, short response OK/NOT OK
    RESP_PRECISE_HEALTH_CHECK,               // longer payload with codes of hardware devices that are not working
    RESP_RATE_OF_PRESSURE_SENSOR_REPORT_SET, // 1 word payload, rate in Hz
    RESP_PRESSURE_SENSOR_VALUE_ONCE,         // 2 word payload pressure value in uint32

    /* messages where the response is not required */
    NORESPREQ_START_SENDING_SENSOR_VALUES = 100,    // no payload
    NORESPREQ_SET_THRUSTERS,                        // 5 words payload of values for thrusters [0,2000]
    NORESPREQ_SET_SERVOS,                           // 2 words payload - first number of servo, second - value [0,100]
    NORESPREQ_SET_AZIMUTHAL_SERVOS,                 // 2 words payload - value servo 0, value servo 1 - both [0,100]
    NORESPREQ_PRESSURE_SENSOR_VALUE_REGULAR_REPORT, // 2 words payload - pressure value in uint32
    NORESPREQ_CLOSE_GRIPPER,                        // no payload
    NORESPREQ_OPEN_GRIPPER,                         // no payload
    NORESPREQ_SET_GRIPPER_HORIZONTAL,               // 1 word payload - value [0,100]
    NORESPREQ_SET_GRIPPER_VERTICAL,                 // 1 word payload - value [0,100]
    NORESPREQ_LAUNCH_TORPEDO,                       // 1 word payload - number of torpedo to launch {1 - left, 2 - right}

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
