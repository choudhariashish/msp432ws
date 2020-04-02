#include <app/app.h>
#include "library/pin_config.h"
#include "library/adc/adc.h"
#include "library/gpio/gpio.h"

Status App::initialize()
{
    Status status;
    status.code = STATUS_CODE::OK;

    status = ADC::initialize();
    status = GPIO_INPUTS::initialize();
    status = GPIO_OUTPUTS::initialize();

    if (status.code == STATUS_CODE::OK)
    {
        // Initialize a thread to monitor ADC.

        int retc;
        int detachState = PTHREAD_CREATE_DETACHED;

        // Set detached state.
        retc = pthread_attr_setdetachstate(&attrs, detachState);
        // Set stack size.
        retc |= pthread_attr_setstacksize(&attrs, THREADSTACKSIZE);
        // Set priority.
        priParam.sched_priority = 1;
        pthread_attr_setschedparam(&attrs, &priParam);
        // Create thread.
        retc = pthread_create(&thread0, NULL, (THREADFUNCPTR) &App::executeTh1, this);
    }

    return status;
}

void * App::executeTh1()
{
    // Sleep time in microseconds (/1000 milliseconds)
    uint32_t period = (50 * 1000);
    uint32_t adcValues[NUM_ADC_INPUTS];
    uint8_t gpioInputValues[NUM_GPIO_INPUTS];
    uint8_t gpioOutputValues[NUM_GPIO_OUTPUTS];

    while (1)
    {
        ADC::read(adcValues);
        GPIO_INPUTS::read(gpioInputValues);
        GPIO_OUTPUTS::read(gpioOutputValues);

        usleep(period);
    }
}
