Setting up work enviornment

1. Download and extract FreeRTOSv10.3.1.zip
2. Download and extract CCS10.0.0.00010_linux-x64.tar.gz
3. Download simplelink_msp432e4_sdk_4_10_00_13.run
4. cd CCS10.0.0.00010_linux-x64/
5. sudo apt-get install libgconf-2-4
6. sudo apt-get install libusb-0.1-4
7. ./ccs_setup_10.0.0.00010.run
8. Click Next, Next
9. Select "SimpleLink MSP432 low power + performance MCUs"
10. Click Forward
11. Select default debug probe selection and continue
12. cd to directory where "simplelink_msp432e4_sdk_4_10_00_13.run" is downloaded
13. chmod +x simplelink_msp432e4_sdk_4_10_00_13.run
14. ./simplelink_msp432e4_sdk_4_10_00_13.run
15. Install to default location, it should detect TI folder

Setup FreeRTOS in CCS

1. In your home directory, do "git clone https://github.com/choudhariashish/msp432ws"
2. Open the Code Composer Studio(CCS) and select default workspace as "msp432ws"
3. Open CCS and in project explorer import CCS projects from "msp432ws" that we just cloned
4. Window->Preferences->Code Composer Studio->Build->Variables and click Add
5. Variable name: FREERTOS_INSTALL_DIR and set value as path to /your/path/FreeRTOSv10.3.1

PIN Functionality

PM3    GPIO        1
PH2    GPIO        2
PN2    GPIO        3
PN3    GPIO        4
PP2    GPIO        5
PL0    GPIO        6
PL1    GPIO        7
PL2    GPIO        8
PL3    GPIO        9
PP5    GPIO       10
PH0    GPIO       11
PH1    GPIO       12
PK6    GPIO       13
PK7    GPIO       14
PC6    GPIO       15
PP4    GPIO       16

PB4    AIN         1
PB5    AIN         2
PK0    AIN         3
PK1    AIN         4
PK2    AIN         5
PK3    AIN         6
PE4    AIN         7
PE5    AIN         8
PE0    AIN         9
PE1    AIN        10
PE2    AIN        11
PE3    AIN        12

PF1    PWM         1
PF2    PWM         2
PF3    PWM         3
PG0    PWM         4
PG1    PWM         5
PK4    PWM         6
PK5    PWM         7
PM0    PWM         8

PL4    TMR         1
PL5    TMR         2
PM1    TMR         3
PM2    TMR         4

PA0    CANRX       1
PA1    CANTX       1

PN5    I2C_SCL     1
PN4    I2C_SDA     1

PQ2    SPI_MOSI    1
PQ3    SPI_MISO    1
PP3    SPI_CS      1
PQ0    SPI_CLK     1

PP0    UART_RX     1
PP1    UART_TX     1
PC4    UART_RX     2
PC5    UART_TX     2
