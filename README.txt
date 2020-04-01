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
12. Open the Code Composer Studio(CCS) and select default workspace example "workspace_v10"
13. Close CCS
14. cd to directory where "simplelink_msp432e4_sdk_4_10_00_13.run" is downloaded
15. chmod +x simplelink_msp432e4_sdk_4_10_00_13.run
16. ./simplelink_msp432e4_sdk_4_10_00_13.run
17. Install to default location, it should detect TI folder

Setup FreeRTOS in CCS

1. Move FreeRTOSv10.3.1 to workspace_v10 directory which just got created
2. In workspace_v10, do "git clone https://github.com/choudhariashish/msp432"
3. Open CCS and in project explorer import CCS project "msp432" that we just cloned
4. Window->Preferences->Code Composer Studio->Build->Variables and click Add
5. Variable name: FREERTOS_INSTALL_DIR and set value as path to /your/path/FreeRTOSv10.3.1
