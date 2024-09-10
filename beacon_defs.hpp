#include "WString.h"
#ifndef BEACON_DEFS_H
#define BEACON_DEFS_H
#define SMOVE(x) (static_cast<SoftwareSerial &&>(x))
#define MOVE(x) (static_cast<String &&>(x))
#define getName(VariableName) #VariableName
#include "SoftwareSerial.h"
#include <Arduino.h>
#include "beacon_confs.hpp"
#include "lib_ics.hpp"

std::atomic<bool> rxPending(false);
String add_leading_zeros(int nonZeroTemp);
void IRAM_ATTR receiveHandler() {
  rxPending.store(true);
}
String conokReturn(String &&coktempStr) {
  Serial.println("conokreturn = " + coktempStr);
  if (coktempStr.indexOf("+EVT:1:") != -1 || coktempStr.indexOf("+EVT:2:") != -1 || coktempStr.indexOf("+EVT:3:") != -1) {
    coktempStr.trim();
    coktempStr = coktempStr.substring(coktempStr.indexOf("+EVT:UNICAST") + 21, coktempStr.length());
    Serial.println("Confirmed OK return an DL with data of => " + coktempStr + " and length of " + String{ coktempStr.length() });
    return String{ coktempStr };
  } else {
    Serial.println("Confirmed OK not returned a DL");
    return String{ "No_DL_data" };
  }
}
class PortHandle {

  public:

    PortHandle(SoftwareSerial &portNew)
      : MySerial(&portNew) {
      Serial.begin(115200);
      MySerial->begin(9600);
      MySerial->setTimeout(5);  //30 mmfph! //100 //1000ms changed to 10ms because of when data transmission if device gets a p2p data when it already has, connection cuts off. I don't know why. Also 10 default. but 8 and 5 needs to be explored.
      MySerial->onReceive(receiveHandler);
      Serial.println("PortHandle started with the reference");
    };
    PortHandle(SoftwareSerial *portNew)
      : MySerial(portNew) {
      Serial.begin(9600);
      MySerial->begin(9600);
      MySerial->setTimeout(1500);
      Serial.println("PortHandle started with the pointer ");
    };
    [[nodiscard]] String listenRes() {
      String holdStr{};
      if (rxPending.load() && MySerial->available()) {
        holdStr = MySerial->readString();
        
        rxPending.store(false);
      }
      holdStr.trim();
      return holdStr;
    }
    void dl_ins_return(String &&coktempStr, int &atime, const char *nString);
    [[nodiscard]] String portSend(String pdata); 
    [[nodiscard]] String portSend(const char *pdata);
  
  private:
    SoftwareSerial *MySerial;
    
  
};

String PortHandle::portSend(String pdata) {

  MySerial->println(pdata);
  delay(10);
 
listenme:
  String resValue = listenRes();
  
  delay(10);  
  
  if (resValue.isEmpty())
    goto listenme;

  return resValue;
  
}
String PortHandle::portSend(const char *pdata) {

  MySerial->println(pdata);
  delay(10);
 
listenme:
  String resValue = listenRes();
  
  delay(10);  
  if (resValue.isEmpty())
    goto listenme;


  return resValue;
}

#endif