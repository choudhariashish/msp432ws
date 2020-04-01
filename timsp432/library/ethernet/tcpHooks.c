#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <pthread.h>

#include <ti/ndk/inc/netmain.h>

#include <ti/ndk/slnetif/slnetifndk.h>
#include <ti/net/slnet.h>
#include <ti/net/slnetif.h>
#include <ti/net/slnetutils.h>

#include <ti/drivers/emac/EMACMSP432E4.h>

#define TCPPORT 1000

#define TCPHANDLERSTACK 2048
#define IFPRI  4   /* Ethernet interface priority */

/* Prototypes */
extern void *tcpHandler(void *arg0);


/*
 *  ======== netIPAddrHook ========
 *  user defined network IP address hook
 */
void netIPAddrHook(uint32_t IPAddr, unsigned int IfIdx, unsigned int fAdd)
{
    pthread_t           thread;
    pthread_attr_t      attrs;
    struct sched_param  priParam;
    int                 retc;
    int                 detachState;
//    uint32_t            hostByteAddr;
    static uint16_t     arg0 = TCPPORT;
    static bool         createTask = true;
    int32_t             status = 0;

    if (fAdd) {
    }
    else {
    }

    /* print the IP address that was added/removed */
//    hostByteAddr = NDK_ntohl(IPAddr);

    /* initialize SlNet interface(s) */
    status = ti_net_SlNet_initConfig();
    if (status < 0)
    {
        while (1);
    }

    if (fAdd && createTask) {
        /*
         *  Create the Task that farms out incoming TCP connections.
         *  arg0 will be the port that this task listens to.
         */

        /* Set priority and stack size attributes */
        pthread_attr_init(&attrs);
        priParam.sched_priority = 1;

        detachState = PTHREAD_CREATE_DETACHED;
        retc = pthread_attr_setdetachstate(&attrs, detachState);
        if (retc != 0) {
            while (1);
        }

        pthread_attr_setschedparam(&attrs, &priParam);

        retc |= pthread_attr_setstacksize(&attrs, TCPHANDLERSTACK);
        if (retc != 0) {
            while (1);
        }

        retc = pthread_create(&thread, &attrs, tcpHandler, (void *)&arg0);
        if (retc != 0) {
            while (1);
        }

        createTask = false;
    }
}

/*
 *  ======== serviceReport ========
 *  NDK service report.  Initially, just reports common system issues.
 */
void serviceReport(uint32_t item, uint32_t status, uint32_t report, void *h)
{
//    static char *taskName[] = {"Telnet", "", "NAT", "DHCPS", "DHCPC", "DNS"};
//    static char *reportStr[] = {"", "Running", "Updated", "Complete", "Fault"};
//    static char *statusStr[] = {"Disabled", "Waiting", "IPTerm", "Failed","Enabled"};

    /* report common system issues */
    if ((item == CFGITEM_SERVICE_DHCPCLIENT) &&
            (status == CIS_SRV_STATUS_ENABLED) &&
            (report & NETTOOLS_STAT_FAULT)) {

        while (1);
    }
}
