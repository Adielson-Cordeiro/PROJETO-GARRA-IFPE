#include <VarSpeedServo.h>

#define pinVRx A2
#define pinVRy A1
#define pinSW 2

#define pinPot1 A4
#define pinPot2 A5

VarSpeedServo myservo;
VarSpeedServo myservo2;
VarSpeedServo myservo3;
VarSpeedServo myservo4;

int pos = 0;


void setup() {
 
 pinMode(pinVRx, INPUT);
 pinMode(pinVRy, INPUT);
 pinMode(pinSW, INPUT_PULLUP);
 
 pinMode(pinPot1, INPUT);
 pinMode(pinPot2, INPUT);
 
 myservo.attach(4);
 myservo2.attach(5);
 myservo3.attach(7);
 myservo4.attach(8);
 
 Serial.begin(9600); 

}

void loop() {
  
 int valorVRx = analogRead(pinVRx);
 int valorVRy = analogRead(pinVRy);
 bool statusSW = digitalRead(pinSW);

 float valorPot1 = analogRead(pinPot1);
 float valorPot2 = analogRead(pinPot2);

 valorVRx = (map(valorVRx,0,1023,0,180));
 Serial.println("Valor VRx: ");
 Serial.println(map(valorVRx,0,1023,0,180));
 Serial.println(" ");

 valorVRy = (map(valorVRy,0,1023,0,180));
 Serial.println("Valor VRy: ");
 Serial.println(map(valorVRy,0,1023,0,180));
 Serial.println(" ");

 valorPot1 = (map(valorPot1,0,1023,0,180));
 Serial.println("Valor VRx2: ");
 Serial.println(map(valorPot1,0,1023,0,180));
 Serial.println(" ");

 valorPot2 = (map(valorPot2,0,1023,0,180));
 Serial.println("Valor VRy2: ");
 Serial.println(map(valorPot2,0,1023,0,180));
 Serial.println(" ");

 myservo.slowmove(valorVRx, 120);
 myservo.slowmove(valorVRy, 120);
 
 myservo3.slowmove(valorPot1, 150);
 myservo4.slowmove(valorPot2, 150);

 //delay(200);


 if (statusSW) {
    Serial.println(" Botão: [Solto] ");
    //delay(200);
  } else {
    for (pos = 0; pos <= 90; pos++){
     Serial.println(" Botão: [Apertado] ");
     myservo2.write(pos);
     delay(15); }
    }
}
