#include "ard.h"
class MouseRptParser : public MouseReportParser
{
protected:
  void OnMouseMove  (MOUSEINFO *mi);
  void OnLeftButtonUp (MOUSEINFO *mi);
  void OnLeftButtonDown (MOUSEINFO *mi);
  void OnRightButtonUp  (MOUSEINFO *mi);
  void OnRightButtonDown  (MOUSEINFO *mi);
  void OnMiddleButtonUp (MOUSEINFO *mi);
  void OnMiddleButtonDown (MOUSEINFO *mi);
  //void OnX1ButtonUp (MOUSEINFO *mi);
  //void OnX1ButtonDown (MOUSEINFO *mi);
  //void OnX2ButtonUp (MOUSEINFO *mi);
  //void OnX2ButtonDown (MOUSEINFO *mi);
  void OnWheelMove (MOUSEINFO *mi);
};
MouseRptParser                               Prs;

void setup()
{
    Serial.begin( 115200 );

    if (Usb.Init() == -1)
        Serial.println("OSC did not start.");

    delay( 200 );

    //next_time = millis() + 5000;

    HidMouse.SetReportParser(0,(HIDReportParser*)&Prs);
}

void loop()
{
  Usb.Task();
}
void mouseCommand(uint8_t mc, int rp){
    Mouse.begin();
    if(rp == 0){Mouse.release(mc);}
    else{Mouse.press(mc);}
    Mouse.end();
}

void MouseRptParser::OnMouseMove(MOUSEINFO *mi)
{
    Mouse.move(mi->dX, mi->dY); 
};
void MouseRptParser::OnLeftButtonUp (MOUSEINFO *mi){mouseCommand(MOUSE_LEFT,0);};
void MouseRptParser::OnLeftButtonDown (MOUSEINFO *mi){mouseCommand(MOUSE_LEFT,1);};

void MouseRptParser::OnRightButtonUp (MOUSEINFO *mi){mouseCommand(MOUSE_RIGHT,0);};
void MouseRptParser::OnRightButtonDown (MOUSEINFO *mi){mouseCommand(MOUSE_RIGHT,1);};

void MouseRptParser::OnMiddleButtonUp (MOUSEINFO *mi){mouseCommand(MOUSE_MIDDLE,0);};
void MouseRptParser::OnMiddleButtonDown (MOUSEINFO *mi){mouseCommand(MOUSE_MIDDLE,1);};

void MouseRptParser::OnWheelMove (MOUSEINFO *mi)
{
  Mouse.begin();
  //Serial.println(mi->dZ);
  Mouse.move(0, 0, mi->dZ);
  Mouse.end();
};
/*
void MouseRptParser::OnX1ButtonUp (MOUSEINFO *mi)
{
    Mouse.begin();
    //Mouse.release(MOUSE_BACK);
    Mouse.end();
};
void MouseRptParser::OnX1ButtonDown (MOUSEINFO *mi)
{
    Mouse.begin();
    //Mouse.press(MOUSE_BACK);
    Mouse.end();
};
void MouseRptParser::OnX2ButtonUp (MOUSEINFO *mi)
{
    Mouse.begin();
    //Mouse.release(MOUSE_FORWARD);
    Mouse.end();
};
void MouseRptParser::OnX2ButtonDown (MOUSEINFO *mi)
{
    Mouse.begin();
    //Mouse.press(MOUSE_FORWARD);
    Mouse.end();
};
*/
