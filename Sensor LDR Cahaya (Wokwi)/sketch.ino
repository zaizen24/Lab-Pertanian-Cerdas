int led1=13; // inisialisasi led1 berada di pin 13
int cahaya=12; // inisialisasi cahaya atau sensor ldr berada di pin 12
void setup() {
  // put your setup code here, to run once:
pinMode (led1,OUTPUT); // mengubah pin mode led1 menjadi output
pinMode(cahaya,INPUT); // mengubah pin mode cahaya menjadi input
Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
int data = analogRead(cahaya); // inisialisai data sama dengan membaca sensor cahaya
Serial.println(data); // menampilkan data di serial monitor dengan baris per baris

if (data > 0){ // jika sensor tidak mendeteksi cahaya maka led akan hidup
  digitalWrite(led1, HIGH);
}
else{ // jika ada cahaya maka led akan mati
  digitalWrite(led1, LOW);
}

//digitalWrite(led1, HIGH);
//delay(500);
//digitalWrite(led1, LOW);
//delay(500);
}
