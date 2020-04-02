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

PM3    GPIO        0
PH2    GPIO        1
PN2    GPIO        2
PN3    GPIO        3
PH0    GPIO        4
PH1    GPIO        5
PK7    GPIO        6
PC6    GPIO        7
PA2    GPIO        8
PA3    GPIO        9
PA4    GPIO       10
PA5    GPIO       11
PA6    GPIO       12
PA7    GPIO       13
PC4    GPIO       14
PC5    GPIO       15

PB4    AIN         0
PB5    AIN         1
PK0    AIN         2
PK1    AIN         3
PK2    AIN         4
PK3    AIN         5
PE4    AIN         6
PE5    AIN         7
PE0    AIN         8
PE1    AIN         9
PE2    AIN        10
PE3    AIN        11

PF1    PWM         0
PF2    PWM         1
PF3    PWM         2
PG0    PWM         3
PG1    PWM         4
PK5    PWM         5

PL4    TMR         0
PL5    TMR         1
PM1    TMR         2
PM2    TMR         3

PA0    CANRX       0
PA1    CANTX       0

PN5    I2C_SCL     0
PN4    I2C_SDA     0

PQ2    SPI_MOSI    0
PQ3    SPI_MISO    0
PP3    SPI_CS      0
PQ0    SPI_CLK     0

PP0    UART_RX     0
PP1    UART_TX     0
PC4    UART_RX     1
PC5    UART_TX     1
