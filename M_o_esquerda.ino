/*---------------------------------------------------------------------------------------------

  Open Sound Control (OSC) library for the ESP8266/ESP32

  Example for sending messages from the ESP8266/ESP32 to a remote computer
  The example is sending "hello, osc." to the address "/test".

  This example code is in the public domain.

  --------------------------------------------------------------------------------------------- */

#include <WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <OSCMessage.h>

char ssid[] = "LUMU";          // your network SSID (name)
char pass[] = "keypasslumu";                    // your network password

WiFiUDP Udp;                                // A UDP instance to let us send and receive packets over UDP
const IPAddress outIp(192, 168, 4, 2);     // remote IP of your computer
const unsigned int outPort = 8333;          // remote port to receive OSC
const unsigned int localPort = 8000;        // local port to listen for OSC packets (actually not used for sending)

//indicador
bool estadoiz1 = false;
bool estadoiz2 = false;
bool estadoiz3 = false;
bool estadoiz4 = false;

//medio
bool estadomz1 = false;
bool estadomz2 = false;
bool estadomz3 = false;
bool estadomz4 = false;

//anelar
bool estadoaz1 = false;
bool estadoaz2 = false;
bool estadoaz3 = false;
bool estadoaz4 = false;

//minimo
bool estadomiz1 = false;
bool estadomiz2 = false;
bool estadomiz3 = false;
bool estadomiz4 = false;


void setup() {

  //indicador
  pinMode(23, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);

  //medio
  pinMode(18, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);

  //anelar
  pinMode(32, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);

  //minimo
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  Serial.begin(115200);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Conectando: ");
  Serial.println(ssid);
  WiFi.softAP(ssid, pass, 1, false, 2);


  Serial.println("");

  Serial.println("WiFi conectado");
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Endereço de IP: ");
  Serial.println(myIP);

  Serial.println("Iniciando UDP");
  Udp.begin(localPort);
  Serial.print("Porta local: ");
  Serial.println(localPort);


}

void loop() {
  // Indicador
  OSCMessage msgiz1("/Esquerda/Indicador/z1");
  OSCMessage msgiz2("/Esquerda/Indicador/z2");
  OSCMessage msgiz3("/Esquerda/Indicador/z3");
  OSCMessage msgiz4("/Esquerda/Indicador/z4");

  //indicador Z1
  if (digitalRead(23) == 0 && estadoiz1 == false) {
    msgiz1.add(36);
    msgiz1.add(127);
    Udp.beginPacket(outIp, outPort);
    msgiz1.send(Udp);
    Udp.endPacket();
    msgiz1.empty();
    estadoiz1 = true;
  }
  if (digitalRead(23) == 1 && estadoiz1 == true) {
    msgiz1.add(36);
    msgiz1.add(0);
    Udp.beginPacket(outIp, outPort);
    msgiz1.send(Udp);
    Udp.endPacket();
    estadoiz1 = false;
  }


  //indicador Z2
  if (digitalRead(22) == 0 && estadoiz2 == false) {
    msgiz2.add(37);
    msgiz2.add(127);
    Udp.beginPacket(outIp, outPort);
    msgiz2.send(Udp);
    Udp.endPacket();
    msgiz2.empty();
    estadoiz2 = true;
  }
  if (digitalRead(22) == 1 && estadoiz2 == true) {
    msgiz2.add(37);
    msgiz2.add(0);
    Udp.beginPacket(outIp, outPort);
    msgiz2.send(Udp);
    Udp.endPacket();
    estadoiz2 = false;
  }


  //indicador Z3
  if (digitalRead(19) == 0 && estadoiz3 == false) {
    msgiz3.add(48);
    msgiz3.add(127);
    Udp.beginPacket(outIp, outPort);
    msgiz3.send(Udp);
    Udp.endPacket();
    msgiz3.empty();
    estadoiz3 = true;
  }
  if (digitalRead(19) == 1 && estadoiz3 == true) {
    msgiz3.add(48);
    msgiz3.add(0);
    Udp.beginPacket(outIp, outPort);
    msgiz3.send(Udp);
    Udp.endPacket();
    estadoiz3 = false;
  }


  //indicador Z4
  if (digitalRead(21) == 0 && estadoiz4 == false) {
    msgiz4.add(49);
    msgiz4.add(127);
    Udp.beginPacket(outIp, outPort);
    msgiz4.send(Udp);
    Udp.endPacket();
    msgiz4.empty();
    estadoiz4 = true;
  }
  if (digitalRead(21) == 1 && estadoiz4 == true) {
    msgiz4.add(49);
    msgiz4.add(0);
    Udp.beginPacket(outIp, outPort);
    msgiz4.send(Udp);
    Udp.endPacket();
    estadoiz4 = false;
  }




  //Medio

  OSCMessage msgmz1("/Esquerda/Medio/z1");
  OSCMessage msgmz2("/Esquerda/Medio/z2");
  OSCMessage msgmz3("/Esquerda/Medio/z3");
  OSCMessage msgmz4("/Esquerda/Medio/z4");

  //medio Z1
  if (digitalRead(18) == 0 && estadomz1 == false) {
    msgmz1.add(38);
    msgmz1.add(127);
    Udp.beginPacket(outIp, outPort);
    msgmz1.send(Udp);
    Udp.endPacket();
    msgmz1.empty();
    estadomz1 = true;
  }
  if (digitalRead(18) == 1 && estadomz1 == true) {
    msgmz1.add(38);
    msgmz1.add(0);
    Udp.beginPacket(outIp, outPort);
    msgmz1.send(Udp);
    Udp.endPacket();
    estadomz1 = false;
  }


  //medio Z2
  if (digitalRead(17) == 0 && estadomz2 == false) {
    msgmz2.add(39);
    msgmz2.add(127);
    Udp.beginPacket(outIp, outPort);
    msgmz2.send(Udp);
    Udp.endPacket();
    msgmz2.empty();
    estadomz2 = true;
  }
  if (digitalRead(17) == 1 && estadomz2 == true) {
    msgmz2.add(39);
    msgmz2.add(0);
    Udp.beginPacket(outIp, outPort);
    msgmz2.send(Udp);
    Udp.endPacket();
    estadomz2 = false;
  }

  //medio Z3
  if (digitalRead(5) == 0 && estadomz3 == false) {
    msgmz3.add(50);
    msgmz3.add(127);
    Udp.beginPacket(outIp, outPort);
    msgmz3.send(Udp);
    Udp.endPacket();
    msgmz3.empty();
    estadomz3 = true;
  }
  if (digitalRead(5) == 1 && estadomz3 == true) {
    msgmz3.add(50);
    msgmz3.add(0);
    Udp.beginPacket(outIp, outPort);
    msgmz3.send(Udp);
    Udp.endPacket();
    estadomz3 = false;
  }


  //medio Z4
  if (digitalRead(16) == 0 && estadomz4 == false) {
    msgmz4.add(51);
    msgmz4.add(127);
    Udp.beginPacket(outIp, outPort);
    msgmz4.send(Udp);
    Udp.endPacket();
    msgmz4.empty();
    estadomz4 = true;
  }
  if (digitalRead(16) == 1 && estadomz4 == true) {
    msgmz4.add(51);
    msgmz4.add(0);
    Udp.beginPacket(outIp, outPort);
    msgmz4.send(Udp);
    Udp.endPacket();
    estadomz4 = false;
  }




  //Medio

  OSCMessage msgaz1("/Esquerda/Anelar/z1");
  OSCMessage msgaz2("/Esquerda/Anelar/z2");
  OSCMessage msgaz3("/Esquerda/Anelar/z3");
  OSCMessage msgaz4("/Esquerda/Anelar/z4");

  //anelar Z1
  if (digitalRead(15) == 0 && estadoaz1 == false) {
    msgaz1.add(40);
    msgaz1.add(127);
    Udp.beginPacket(outIp, outPort);
    msgaz1.send(Udp);
    Udp.endPacket();
    msgaz1.empty();
    estadoaz1 = true;
  }
  if (digitalRead(15) == 1 && estadoaz1 == true) {
    msgaz1.add(40);
    msgaz1.add(0);
    Udp.beginPacket(outIp, outPort);
    msgaz1.send(Udp);
    Udp.endPacket();
    estadoaz1 = false;
  }

  //anelar Z2
  if (digitalRead(32) == 0 && estadoaz2 == false) {
    msgaz2.add(72);
    msgaz2.add(127);
    Udp.beginPacket(outIp, outPort);
    msgaz2.send(Udp);
    Udp.endPacket();
    msgaz2.empty();
    estadoaz2 = true;
  }
  if (digitalRead(32) == 1 && estadoaz2 == true) {
    msgaz2.add(72);
    msgaz2.add(0);
    Udp.beginPacket(outIp, outPort);
    msgaz2.send(Udp);
    Udp.endPacket();
    estadoaz2 = false;
  }

  //anelar Z3
  if (digitalRead(27) == 0 && estadoaz3 == false) {
    msgaz3.add(52);
    msgaz3.add(127);
    Udp.beginPacket(outIp, outPort);
    msgaz3.send(Udp);
    Udp.endPacket();
    msgaz3.empty();
    estadoaz3 = true;
  }
  if (digitalRead(27) == 1 && estadoaz3 == true) {
    msgaz3.add(52);
    msgaz3.add(0);
    Udp.beginPacket(outIp, outPort);
    msgaz3.send(Udp);
    Udp.endPacket();
    estadoaz3 = false;
  }

  //anelar Z4
  if (digitalRead(14) == 0 && estadoaz4 == false) {
    msgaz4.add(73);
    msgaz4.add(127);
    Udp.beginPacket(outIp, outPort);
    msgaz4.send(Udp);
    Udp.endPacket();
    msgaz4.empty();
    estadoaz4 = true;
  }
  if (digitalRead(14) == 1 && estadoaz4 == true) {
    msgaz4.add(73);
    msgaz4.add(0);
    Udp.beginPacket(outIp, outPort);
    msgaz4.send(Udp);
    Udp.endPacket();
    estadoaz4 = false;
  }



  OSCMessage msgmiz1("/Esquerda/Minimo/z1");
  OSCMessage msgmiz2("/Esquerda/Minimo/z2");
  OSCMessage msgmiz3("/Esquerda/Minimo/z3");
  OSCMessage msgmiz4("/Esquerda/Minimo/z4");

  //Minino Z1
  if (digitalRead(4) == 0 && estadomiz1 == false) {
    msgmiz1.add(53);
    msgmiz1.add(127);
    Udp.beginPacket(outIp, outPort);
    msgmiz1.send(Udp);
    Udp.endPacket();
    msgmiz1.empty();
    estadomiz1 = true;
  }
  if (digitalRead(4) == 1 && estadomiz1 == true) {
    msgmiz1.add(53);
    msgmiz1.add(0);
    Udp.beginPacket(outIp, outPort);
    msgmiz1.send(Udp);
    Udp.endPacket();
    estadomiz1 = false;
  }

  //Minino Z2
  if (digitalRead(13) == 0 && estadomiz2 == false) {
    msgmiz2.add(54);
    msgmiz2.add(127);
    Udp.beginPacket(outIp, outPort);
    msgmiz2.send(Udp);
    Udp.endPacket();
    msgmiz2.empty();
    estadomiz2 = true;
  }
  if (digitalRead(13) == 1 && estadomiz2 == true) {
    msgmiz2.add(54);
    msgmiz2.add(0);
    Udp.beginPacket(outIp, outPort);
    msgmiz2.send(Udp);
    Udp.endPacket();
    estadomiz2 = false;
  }


  //Minino Z3
  if (digitalRead(2) == 0 && estadomiz3 == false) {
    msgmiz3.add(65);
    msgmiz3.add(127);
    Udp.beginPacket(outIp, outPort);
    msgmiz3.send(Udp);
    Udp.endPacket();
    msgmiz3.empty();
    estadomiz3 = true;
  }
  if (digitalRead(2) == 1 && estadomiz3 == true) {
    msgmiz3.add(65);
    msgmiz3.add(0);
    Udp.beginPacket(outIp, outPort);
    msgmiz3.send(Udp);
    Udp.endPacket();
    estadomiz3 = false;
  }


  //Minino Z4
  if (digitalRead(12) == 0 && estadomiz4 == false) {
    msgmiz4.add(66);
    msgmiz4.add(127);
    Udp.beginPacket(outIp, outPort);
    msgmiz4.send(Udp);
    Udp.endPacket();
    msgmiz4.empty();
    estadomiz4 = true;
  }
  if (digitalRead(12) == 1 && estadomiz4 == true) {
    msgmiz4.add(66);
    msgmiz4.add(0);
    Udp.beginPacket(outIp, outPort);
    msgmiz4.send(Udp);
    Udp.endPacket();
    estadomiz4 = false;
  }
}
