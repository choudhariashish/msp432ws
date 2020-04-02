#include "ti_drivers_config.h"

#include "library/adc/adc.h"

#define ADC_SAMPLE_COUNT  (10)

uint32_t adcValues[NUM_ADC_INPUTS];
ADC_Handle   adc[NUM_ADC_INPUTS];
ADC_Params   params;
int_fast16_t res;

Status ADC::initialize()
{
    Status status;
    status.code = STATUS_CODE::OK;

    ADC_init();
    ADC_Params_init(&params);

    uint8_t pin = 0;

    while (pin < NUM_ADC_INPUTS)
    {
        adc[pin] = ADC_open(pin, &params);

        if (adc[pin] == NULL)
        {
            status.code = STATUS_CODE::FAIL;
            while (1) {}
        }

        pin++;
    }

    return status;
}

Status ADC::read(uint32_t *buffer)
{
    Status status;
    status.code = STATUS_CODE::OK;
    uint16_t adcValue;

    uint8_t pin = 0;

    while (pin < NUM_ADC_INPUTS)
    {
        res = ADC_convert(adc[pin], &adcValue);

        if (res == ADC_STATUS_SUCCESS)
        {
            buffer[pin] = ADC_convertRawToMicroVolts(adc[pin], adcValue);
        }
        pin++;
    }

    return status;
}
