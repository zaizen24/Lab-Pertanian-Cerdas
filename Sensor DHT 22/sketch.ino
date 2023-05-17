#include <LiquidCrystal_I2C.h> // memasukkan library lcd
#include <DHT.h> // memasukkan library sensor dht

#define DHTPIN 8 // definisikan dhtpin di pin 9 pada arduino
#define DHTTYPE DHT22 // definisikan tipe dht yaitu dht 22
DHT dht (DHTPIN, DHTTYPE); // inisialisasi dht bisa membaca dhtpin dan dhttipe
LiquidCrystal_I2C lcd(0x27, 16, 2); // inisialisasi lcd untuk mengontrol display lcd

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // memulai serial monitor
  Serial.println("Sistem Monitoring Suhu dan Kelembapan"); // menampilkan pada serial monitor
  lcd.begin(16, 2); // memulai lcd dengan 16 karakter dan 2 baris
  dht.begin(); // memulai sensor dht
}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature(); // inisialisasi t untuk membaca suhu dan bertipe data float
  float h = dht.readHumidity(); // inisialisasi h untuk membaca kelembapan dan bertipe data float
  delay(1000); // delay 1000 milisecond atau 1 detik

// kondisi jika sensor tidak dapat membaca suhu dan kelembapan
  if (isnan (t) || isnan (h)){
    Serial.println("Sensor tidak dapat membaca"); // menampilkan string tersebut
    return;
  }

  // Menampilkan ke serial monitor
  Serial.print("Suhu :");
  Serial.print(t);
  Serial.print(" C");
  Serial.print("\n");
  Serial.print("Kelembapan :");
  Serial.print(h);
  Serial.print("%");
  Serial.print("\n");

  // Menampilkan ke lcd
  lcd.setCursor(0,0);
  lcd.print("Suhu:");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Kelmbpan:");
  lcd.print(h);
  lcd.print(" %");
}
