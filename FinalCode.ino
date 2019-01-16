//5 LEDs, chacun avec sa fermeture

// Basic Bluetooth sketch HC-05_03 Using the state pin 
// Connect the HC-05 module and communicate using the serial monitor
//
// The HC-05 defaults to communication mode when first powered on.
// The default baud rate for communication mode is 9600

//Connections
// Connect the HC-05 TX to Arduino pin 2 
// Connect the HC-05 RX to Arduino pin 3
// Connect the HC-05 STATE pin to Arduino pin 4
// alb en 13
// rouge en pin 12
// vert en pin 11
// jaune en pin 10
// blue en 9
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
 
char c = ' ';
String cuvant ;
String on = "on";
String off = "off";

// BTconnected will = false when not connected and true when connected
boolean BTconnected = false;
 
// connect the STATE pin to Arduino pin D4
const byte BTpin = 4;
int ledV = 11;
int ledA = 9;
int ledR = 12;
int ledG = 10;
int ledAl = 13;

 
void setup() {
    // set the BTpin for input
    pinMode(BTpin, INPUT);   
    pinMode(ledV,OUTPUT);
    pinMode(ledA,OUTPUT);
    pinMode(ledR,OUTPUT);
    pinMode(ledAl,OUTPUT);
    pinMode(ledG,OUTPUT);
    
    // start serial communication with the serial monitor on the host computer
    Serial.begin(19200);
    Serial.println("Arduino is ready");
    Serial.println("Connect the HC-05 to an Android device to continue");
 
    // wait until the HC-05 has made a connection
    while (!BTconnected){
      if ( digitalRead(BTpin)==HIGH)  { BTconnected = true;};
    }
    Serial.println("HC-05 is now connected");
 
    // Start serial communication with the bluetooth module
    // HC-05 default serial speed for communication mode is 9600 but can be different
    BTserial.begin(9600); 
    BTserial.write('x'); 
}
 
void loop(){
 
    // Keep reading from the HC-05 and send to Arduino Serial Monitor
    if (BTserial.available()){     
        c = BTserial.read();
        //Serial.write(c);
        //Serial.println("");
        switch(c){

      //allumer chaque led          
          case 'v':
            digitalWrite(ledV,HIGH);
            //delay(1000);
            BTserial.write("Vert on");
            BTserial.println("");
            Serial.println("Vert on");
            break;

          case 'r':
            digitalWrite(ledR,HIGH);
            BTserial.write("Rouge on");
            BTserial.println("");
            Serial.println("Rouge on");
            break;
          
          case 'a':
            digitalWrite(ledA,HIGH);
            BTserial.write("Blue on");
            BTserial.println("");
            Serial.println("Blue on");
            break;

          case 'w': 
            digitalWrite(ledAl,HIGH);
            BTserial.write("Blanc on");
            BTserial.println("");
            Serial.println("Blanc on");
            break;
          
          case 'g':
            digitalWrite(ledG,HIGH);
            BTserial.write("Jaune on");
            BTserial.println("");
            Serial.println("Jaune on");
            break;

      //eteindre chaque led separament          
          case 'i':
            digitalWrite(ledV,LOW);
            BTserial.write("Vert off");
            BTserial.println("");
            Serial.println("Vert off");
            break;
         
         case 'f':
            digitalWrite(ledA,LOW);
            BTserial.write("Blue off");
            BTserial.println("");
            Serial.println("Blue off");
            break;
         
         case 'c':
            digitalWrite(ledR,LOW);
            BTserial.write("Rouge off");
            BTserial.println("");
            Serial.println("Rouge off");
            break;

          case 'h':
            digitalWrite(ledG,LOW);
            BTserial.write("Jaune off");
            BTserial.println("");
            Serial.println("Jaune off");
            break;

          case 'e':
            digitalWrite(ledAl,LOW);
            BTserial.write("Blanc off");
            BTserial.println("");
            Serial.println("Blanc off");
            break;

    //eteindre tous les LEDs
          case 'T':
            digitalWrite(ledV,LOW);
            digitalWrite(ledA,LOW);
            digitalWrite(ledR,LOW);
            digitalWrite(ledG,LOW);
            digitalWrite(ledAl,LOW);
            BTserial.write("TOUT off");
            BTserial.println("");
            Serial.println("TOUT off");
            break;

      //allumer tout
            case 'O':
              digitalWrite(ledV,HIGH);
              digitalWrite(ledA,HIGH);
              digitalWrite(ledR,HIGH);
              digitalWrite(ledG,HIGH);
              digitalWrite(ledAl,HIGH);
              BTserial.write("TOUT on");
              BTserial.println("");
              Serial.println("TOUT on");
              break;

          }
    }

}
