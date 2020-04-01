#ifndef APP_APP_H_
#define APP_APP_H_

#include "app/status_code.h"

class App
{
public:

    static Status initialize()
    {
        Status status;
        status.code = STATUS_CODE::OK;
        return status;
    }
};


#endif /* APP_APP_H_ */
