#include <Servo.h>
int Pir = 8;
int statusPir = 0;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Smart Door Using Motion Sensor");
  myservo.attach(6);
  pinMode(Pir, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  statusPir = digitalRead(Pir);
  if (statusPir = HIGH) {
    myservo.write(45);
    delay(1000);
    myservo.write(0);
    delay(1000);
    myservo.write(90);
    delay(1000);
    Serial.println("Pintu Terbuka");
  }
  else {
    myservo.write(135);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(90);
    delay(1000);
    Serial.println("Pintu Tertutup");
  }
  delay(1000);
}
