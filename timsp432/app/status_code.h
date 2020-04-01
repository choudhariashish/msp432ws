#ifndef STATUS_CODE_H_
#define STATUS_CODE_H_

#include <stdint.h>

#define STATUS_MSG_SIZE    32

enum STATUS_CODE
{
    OK,
    FAIL
};

struct Status
{
    uint8_t code;
    char message[STATUS_MSG_SIZE];
};

#endif /* STATUS_CODE_H_ */
