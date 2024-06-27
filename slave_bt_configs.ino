#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

// SoftwareSerial bluetoothSerial(10, 11);
SoftwareSerial bluetoothSerial(10, 11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buzzer = 7;

void initComponents() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);
  // bluetoothSerial.begin(9600);

  pinMode(buzzer, OUTPUT);

  lcd.init();
}

void operateBuzzer() {
  tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);
  delay(1000);
}

void setup() {
  initComponents();
}

void loop() {
  if (bluetoothSerial.available()) {
    String bluetoothData = bluetoothSerial.readString();
    Serial.print(bluetoothData);
    lcd.print("Purchase success!");
    operateBuzzer();

    lcd.clear();
    lcd.backlight();
    lcd.setCursor(1, 0);
  }
  if (Serial.available()) {
    String serialData = Serial.readString();
    bluetoothSerial.write(serialData.c_str());
  }
}