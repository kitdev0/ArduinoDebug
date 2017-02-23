
// #define _USE_CUSTOM_SOFTWARE_SERAIL  //Uncomment this if use Custom Software serial
// #define _USE_SOFTWARE_SERAIL         //Uncomment this if use Software serial
#include "ArduinoDebug.h"
//Please Define Software serial here if you use Software Serial to Debuger port.
#if defined(_USE_CUSTOM_SOFTWARE_SERAIL)
#include <CustomSoftwareSerial.h>
CustomSoftwareSerial _MY_SOFTWARE_SERIAL(_SOFTWARE_SERIAL_RX_PIN, _SOFTWARE_SERIAL_TX_PIN, false);
#elif defined(_USE_SOFTWARE_SERAIL)
#include <SoftwareSerial.h>
SoftwareSerial _MY_SOFTWARE_SERIAL(_SOFTWARE_SERIAL_RX_PIN, _SOFTWARE_SERIAL_TX_PIN, false);
#endif

ARDUINO_DEBUG debug("MAIN");

void setup()
{
  debug.init();
  debug.sayln("Start programe...");
  // Serial.begin(115200);
  // Serial.println("Hi..");
}

void loop()
{

}
