/*****************************************************************************
 * main.c
 *****************************************************************************/

/***************************** Include Files **********************************/
#include <stdio.h>

#include <sys/platform.h>
//#include "adi_initialize.h"
#include "Communication.h"
//#include "Timer.h"
//#include "Test.h"
//#include "Test_Config.h"

extern ADI_UART_HANDLE          hUartDevice __attribute__ ((aligned (4)));
//extern int32_t adi_initpinmux(void);
	typedef enum
{
CMD_LORAPARAMETER = 0xD6, /* Gets or Sets the LoRa modulation parameters */
CMD_LOCALREAD = 0xE2, /* Gets the ID, NET and UNIQUE ID info from the local device */
CMD_REMOTEREAD = 0xD4, /* Gets the ID, NET and UNIQUE ID info from a remote device */
CMD_WRITECONFIG = 0xCA, /* Writes configuration info to the device, i.e. NET and ID */
CMD_GPIOCONFIG = 0xC2, /* Configures a given GPIO pin to a desired mode, gets or sets its value */
CMD_DIAGNOSIS = 0xE7, /* Gets diagnosis information from the device */
CMD_READNOISE = 0xD8, /* Reads the noise floor on the current channel */
CMD_READRSSI = 0xD5, /* Reads the RSSI between the device and a neighbour */
CMD_TRACEROUTE = 0xD2, /* Traces the hops from the device to the master */
CMD_SENDTRANSP = 0x28 /* Sends a packet to the device's transparent serial port */
} Cmd_Typedef;
typedef struct
{
	uint8_t buffer[237];
	uint8_t size;

	}comando;

void uartsendcom(uint8_t * ptr,uint8_t  size){
	for(int i=0;i<size;i++){
		uint32_t error;
		adi_uart_Write(hUartDevice,ptr,1,0,&error);

	}
}
int main(int argc, char *argv[])
{	comando frame;
	frame.size = 9;
	frame.buffer[0]=0x00;
	frame.buffer[1]=0x01;
	frame.buffer[2]=CMD_REMOTEREAD;
	frame.buffer[3]=0x00;
	frame.buffer[4]=0x00;
	frame.buffer[5]=0x00;
	frame.buffer[6]=0x00;
	frame.buffer[7]=0x00;

	while(1){
		uartsendcom(&frame.buffer[0],frame.size);

	}

}
