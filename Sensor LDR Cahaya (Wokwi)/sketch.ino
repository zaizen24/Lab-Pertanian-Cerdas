int led1=13;
int cahaya=12;
void setup() {
  // put your setup code here, to run once:
pinMode (led1,OUTPUT);
pinMode(cahaya,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int data = analogRead(cahaya);
Serial.println(data);

if (data > 500){
  digitalWrite(led1, HIGH);
}
else{
  digitalWrite(led1, LOW);
}

//digitalWrite(led1, HIGH);
//delay(500);
//digitalWrite(led1, LOW);
//delay(500);
}
