#include <hidboot.h>
#include <Mouse.h>
USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<HID_PROTOCOL_MOUSE>    HidMouse(&Usb);
const byte buffer = 10;
char commandList[buffer];
byte charLimit,inputs,counter;
signed char moveX, moveY,remainderX,remainderY;
int inputInt = 0;
float inputFloat = 0.0;
char inputCsvString[12];
int x;
int y;
int shoot;
long fullDist;
int count;
