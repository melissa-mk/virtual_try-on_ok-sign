#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x3F for a 16 chars and 2 line display

SoftwareSerial bluetoothSerial(10, 11); // RX, TX pins for SoftwareSerial
int buzzerPin = 7;
void setup() {
    Serial.begin(9600); // Serial monitor for debugging
    pinMode(buzzerPin,OUTPUT);
    bluetoothSerial.begin(9600); // Bluetooth serial connection

    lcd.init();
    lcd.clear();
    lcd.backlight(); // Make sure backlight is on

    // Print a message on both lines of the LCD.
    lcd.setCursor(2,0); //Set cursor to character 2 on line 0
    lcd.print("Welcome :) !");

    lcd.setCursor(2,1); //Move cursor to character 2 on line 1
    lcd.print("GLASS-SHOP");
}

void loop() {
    // Read data from Bluetooth module (slave module)
    if (bluetoothSerial.available()) {
        String receivedData = bluetoothSerial.readString(); // Read the data received from Bluetooth module
        Serial.println("Received data from slave: " + receivedData); // Print received data to serial monitor (for debugging)
        
        lcd.setCursor(2,0); //Set cursor to character 2 on line 0
        lcd.print("Processing... !");

        lcd.setCursor(2,1); //Move cursor to character 2 on line 1
        lcd.print("Purchase done");

        // Example: Send received data back to slave HC-05 module
        bluetoothSerial.write(receivedData.c_str()); // Uncomment to send data back to slave
    }

    // Read data from Serial monitor (connected to your computer running Python script)
    if (Serial.available()) {
        String sendData = Serial.readString(); // Read the data from Serial monitor
        bluetoothSerial.write(sendData.c_str()); // Send data received from Serial monitor over Bluetooth to slave HC-05 module
        digitalWrite(buzzerPin,HIGH);
        delay(200);
        digitalWrite(buzzerPin,LOW);
        // Print the sent data to serial monitor (for debugging)
        Serial.println("Sent data to slave: " + sendData);
    }
}