#ifndef _USB_H_
#define _USB_H_

#include "usb_device.h"

#define KEYB_BUFFER_SIZE 8
extern uint8_t Usb_keyboardBuffer[KEYB_BUFFER_SIZE];
extern USBD_HandleTypeDef hUsbDeviceFS;
extern void Usb_SendKeyPress(uint8_t modifier,uint8_t keycode);
extern void Usb_ReleaseKeys(void);

//Usage ID for the keycodes in the input report buffer [see usb documentation]
#define USB_USAGE_ID_A          0x04
#define USB_USAGE_ID_B          0x05
#define USB_USAGE_ID_C          0x06
#define USB_USAGE_ID_D          0x07
#define USB_USAGE_ID_E          0x08
#define USB_USAGE_ID_F          0x09
#define USB_USAGE_ID_G          0x0A
#define USB_USAGE_ID_H          0x0B
#define USB_USAGE_ID_I          0x0C
#define USB_USAGE_ID_J          0x0D
#define USB_USAGE_ID_K          0x0E
#define USB_USAGE_ID_L          0x0F
#define USB_USAGE_ID_M          0x10
#define USB_USAGE_ID_N          0x11
#define USB_USAGE_ID_O          0x12
#define USB_USAGE_ID_P          0x13
#define USB_USAGE_ID_Q          0x14
#define USB_USAGE_ID_R          0x15
#define USB_USAGE_ID_S          0x16
#define USB_USAGE_ID_T          0x17
#define USB_USAGE_ID_U          0x18
#define USB_USAGE_ID_V          0x19
#define USB_USAGE_ID_W          0x1A
#define USB_USAGE_ID_X          0x1B
#define USB_USAGE_ID_Y          0x1C
#define USB_USAGE_ID_Z          0x1D
#define USB_USAGE_ID_BACKSPACE  0x2A
#define USB_USAGE_ID_SPACE      0x2C
#define USB_USAGE_ID_PERIOD     0x37
#define LEFT_SHIFT              0x02
#define USB_USAGE_ID_0          0x27
#define USB_USAGE_ID_1          0x1E
#define USB_USAGE_ID_2          0x1F
#define USB_USAGE_ID_3          0x20
#define USB_USAGE_ID_4          0x21
#define USB_USAGE_ID_5          0x22
#define USB_USAGE_ID_6          0x23
#define USB_USAGE_ID_7          0x24
#define USB_USAGE_ID_8          0x25
#define USB_USAGE_ID_9          0x26

#endif//_USB_H_
