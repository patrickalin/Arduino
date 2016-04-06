/*
 * Module de réception de signaux 443 Mhz, rectangulaire
 * Importer RCSwithch.zip dans IDE arduino
 * 
 * Affiche le signal reçu en 443 Mhz
 * 
 * Face au module à partir de la gauche 4 pin's
 * 1 vcc = 5v
 * 2 vide
 * 3 data =  du coté digital 2, interrupt 0
 * 4 gnd = masse
 * 
 * Compilation donne 2 warnings dans bin2tristate(char*)
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
//int RELAY1  = 7;

void setup() {
  Serial.begin(9600);
  
  Serial.println("Initialisation");
  
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
  
  pinMode(RELAY1, OUTPUT);
}

void loop() {
  if (mySwitch.available()) {
      output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
      int value = mySwitch.getReceivedValue();
      
      if (value==1361) {
        Serial.print("portail");
        digitalWrite(RELAY1,HIGH); // Turns ON Relays 1
        Serial.println("Light ON");
        delay(4000); // Wait 2 seconds
        digitalWrite(RELAY1,LOW); // Turns Relay Off
        Serial.println("Light OFF");
        delay(2000);
      } else {
        Serial.print(value);
      }
      
      mySwitch.resetAvailable();
  }
}
