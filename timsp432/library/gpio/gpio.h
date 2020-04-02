#ifndef LIBRARY_GPIO_GPIO_H_
#define LIBRARY_GPIO_GPIO_H_

#include "library/status_code.h"
#include "library/pin_config.h"


class GPIO_INPUTS
{
public:

    static Status initialize();
    static void read(uint8_t *buffer);
};

class GPIO_OUTPUTS
{
public:

    static Status initialize();

    // value: PIN_STATE -> HIGH/LOW
    static void write(uint8_t pin, PIN_STATE value);
    static void read(uint8_t *buffer);
};

#endif /* LIBRARY_GPIO_GPIO_H_ */
