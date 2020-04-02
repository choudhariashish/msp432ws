#ifndef LIBRARY_ADC_ADC_H_
#define LIBRARY_ADC_ADC_H_

#include <ti/drivers/ADC.h>

#include "library/status_code.h"
#include "library/pin_config.h"


class ADC
{
public:

    static Status initialize();
    static Status read(uint32_t *buffer);
};



#endif /* LIBRARY_ADC_ADC_H_ */
