#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "180b4ac2-c614-487f-a02b-4da24797b553";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onPresa1Change();
void onPresa2Change();
void onPresa3Change();
void onPresa4Change();

CloudSmartPlug presa1;
CloudSmartPlug presa2;
CloudSmartPlug presa3;
CloudSmartPlug presa4;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(presa1, READWRITE, ON_CHANGE, onPresa1Change);
  ArduinoCloud.addProperty(presa2, READWRITE, ON_CHANGE, onPresa2Change);
  ArduinoCloud.addProperty(presa3, READWRITE, ON_CHANGE, onPresa3Change);
  ArduinoCloud.addProperty(presa4, READWRITE, ON_CHANGE, onPresa4Change);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
