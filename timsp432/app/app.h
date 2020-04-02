#ifndef APP_APP_H_
#define APP_APP_H_

#include <pthread.h>

#include "library/status_code.h"

#define THREADSTACKSIZE   (768)
typedef void * (*THREADFUNCPTR)(void *);

class App
{
public:

    Status initialize();

private:

    // Thread 1
    pthread_t           thread0;
    pthread_attr_t      attrs;
    struct sched_param  priParam;
    void * executeTh1();
};


#endif /* APP_APP_H_ */
