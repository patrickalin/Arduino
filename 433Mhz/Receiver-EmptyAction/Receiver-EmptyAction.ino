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
 * Mettre une antenne en bas à gauche
 * 
 * Compilation donne 2 warnings dans bin2tristate(char*)
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  
  Serial.println("Initialisation");
  
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {

      //Display Info
      output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
      int value = mySwitch.getReceivedValue();
      
      mySwitch.resetAvailable();
  }
}
