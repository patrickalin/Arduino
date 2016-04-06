/*
 * Module d'émission de signaux 443 Mhz, carré
 * Importer RCSwithch.zip dans IDE arduino
 * 
 * Emet un signal en 443 Mhz
 * 
 * Face au module à partir de la gauche 3 pin's
 * 1 data = du coté digital 10
 * 2 vcc = 5v
 * 3 gnd = masse
 * 
 * Mettre une antenne en haut à droite
*/


#include <RCSwitch.h>
 
RCSwitch mySwitch = RCSwitch();
 
unsigned long Lampe_bureau_OFF = 5393;
unsigned long Lampe_bureau_ON  = 5201;
 
unsigned long Lampe_salon_OFF  = 961256704;
unsigned long Lampe_salon_ON   = 894147840;
 
 
void setup() {
  Serial.begin(9600);
  
  // Emetteur connecté au pin #10 de l'Arduino  
  mySwitch.enableTransmit(10);
  Serial.println("init");
}
 
void loop() {
  Serial.print("allumeBureau");
  mySwitch.send(Lampe_bureau_ON, 24);
  delay(1000);  
  Serial.println("eteintSalon");
  mySwitch.send(Lampe_bureau_OFF, 24);
  delay(1000);  
  Serial.println("allumeSalon");
  mySwitch.send(Lampe_salon_ON, 24);
  delay(1000);  
  Serial.println("eteinSalon");
  mySwitch.send(Lampe_salon_OFF, 24);
  delay(5000);
}
