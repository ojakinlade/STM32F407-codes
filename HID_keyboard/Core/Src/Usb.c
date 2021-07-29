#include "Usb.h"
#include "usbd_hid.h"
#include <stdint.h>

uint8_t Usb_KeyboardBuffer[KEYB_BUFFER_SIZE] = {0};

void Usb_SendKeyPress(uint8_t modifier,uint8_t keycode){
	Usb_KeyboardBuffer[0] = modifier;
	Usb_KeyboardBuffer[2] = keycode;
	USBD_HID_SendReport(&hUsbDeviceFS,Usb_KeyboardBuffer,KEYB_BUFFER_SIZE);
	HAL_Delay(10);
}

void Usb_ReleaseKeys(void){
	Usb_KeyboardBuffer[0] = 0x00;
	Usb_KeyboardBuffer[2] = 0x00;
	USBD_HID_SendReport(&hUsbDeviceFS,Usb_KeyboardBuffer,KEYB_BUFFER_SIZE);
	HAL_Delay(10);
}


