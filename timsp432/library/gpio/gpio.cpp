#include "ti_drivers_config.h"
#include <ti/drivers/GPIO.h>

#include "library/gpio/gpio.h"


// GPIO_INPUTS

Status GPIO_INPUTS::initialize()
{
    GPIO_init();

    Status status;
    status.code = STATUS_CODE::OK;

    uint8_t pin = 0;
    while (pin < NUM_GPIO_INPUTS)
    {
        GPIO_setConfig(pin, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_HIGH);
        pin++;
    }

    return status;
}

void GPIO_INPUTS::read(uint8_t *buffer)
{
    uint8_t pin = 0;
    while (pin < NUM_GPIO_INPUTS)
    {
        buffer[pin] = GPIO_read(pin);
        pin++;
    }
}


// GPIO_OUTPUTS

Status GPIO_OUTPUTS::initialize()
{
    GPIO_init();

    Status status;
    status.code = STATUS_CODE::OK;

    uint8_t pin = NUM_GPIO_INPUTS;
    while (pin < NUM_GPIO_OUTPUTS)
    {
        GPIO_setConfig(pin, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
    }

    return status;
}

void GPIO_OUTPUTS::write(uint8_t pin, PIN_STATE value)
{
    GPIO_write(NUM_GPIO_INPUTS + pin, value);
}

void GPIO_OUTPUTS::read(uint8_t *buffer)
{
    uint8_t pin = NUM_GPIO_INPUTS;

    while (pin < NUM_GPIO_OUTPUTS)
    {
        buffer[pin] = GPIO_read(pin);
        pin++;
    }
}
