#include <hidboot.h>
#include <Mouse.h>
USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<HID_PROTOCOL_MOUSE>    HidMouse(&Usb);
const byte buffer = 10;
char commandList[buffer];
byte charLimit,inputs,counter;
