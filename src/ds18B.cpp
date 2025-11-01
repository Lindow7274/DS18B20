#include <OneWire.h>
#include <DS18B20.h>
#include <LiquidCrystal.h>
#include <Arduino.h>

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
LiquidCrystal lcd(12, 11, 6, 5, 4, 3); //LiquidCrystal(rs, enable, d4, d5, d6, d7);

byte addr1[8], addr2[8];

float a3tiniTemp(byte address[8]) {
  byte data[9];

  oneWire.reset();
  oneWire.select(address);
  oneWire.write(0xBE);  // to fetch the temperature register

  for (int i = 0; i < 9; i++) data[i] = oneWire.read();

  int16_t raw = (data[1] << 8) | data[0];
  return (float)raw / 16.0;
}

void ejbidlilAddress(byte addr[8]) {
  for (int i = 0; i < 8; i++) {
    if (addr[i] < 16) Serial.print("0"); // writes every byte that less than 16 bits
    Serial.print(addr[i], HEX);
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);
 
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.home();

  if (oneWire.search(addr1)) {
    Serial.print("Sensor 1: ");
    ejbidlilAddress(addr1);
    lcd.print("Sensor 1 found");
    lcd.setCursor(0, 1);
    lcd.print("Addr1: ");
    for 
    (int i = 0; i < 8; i++) {
      if (addr1[i] < 16) lcd.print("0");
      lcd.print(addr1[i], HEX);
    }
    for (int u = 0; u < 7; u++) {
      lcd.scrollDisplayLeft();
      delay(300);
    }
    delay(2000);

  } else {
    Serial.println("No sensor 1 found");
    lcd.print("No sensor 1");
  }

  
if (oneWire.search(addr2)) {
    Serial.print("Sensor 2: ");
    ejbidlilAddress(addr2);
    lcd.clear();
    lcd.home();
    lcd.print("Sensor 2 found");
    lcd.setCursor(0, 1);
    lcd.print("Addr2: ");
for 
    (int i = 0; i < 8; i++) {
      if (addr2[i] < 16) lcd.print("0");
      lcd.print(addr2[i], HEX);
    }
    for (int u = 0; u < 7; u++) {
      lcd.scrollDisplayLeft();
      delay(300);
    }
    delay(2000);
  } else {
    Serial.println("No sensor 2 found");
    lcd.print("No sensor 2");
  }

  oneWire.reset_search();
}

/*void loop() {
  
  oneWire.reset();
  oneWire.skip();      
  oneWire.write(0x44);  
  delay(750);           

  
  float temp1 = a3tiniTemp(addr1);
  Serial.print("Sensor 1: ");
  Serial.println(temp1);
  lcd.clear();
  lcd.home();
  lcd.print("Temperature 1:");
  lcd.setCursor(0, 1);
  lcd.print(temp1);
  delay(2000);


  float temp2 = a3tiniTemp(addr2);
  Serial.print("Sensor 2: ");
  Serial.println(temp2);
lcd.clear();
  lcd.home();
  lcd.print("Temperature 2:");
  lcd.setCursor(0, 1);
  lcd.print(temp2);
  delay(2000);
  Serial.println("--------------------");
}
*/
 // or
void loop() {
  
  oneWire.reset();
  oneWire.skip();      
  oneWire.write(0x44);  
  delay(750);           

  
  float temp1 = a3tiniTemp(addr1);
  Serial.print("Sensor 1: ");
  Serial.println(temp1);
  lcd.clear();
  lcd.home();
  lcd.print("Temp1:");
  lcd.print(temp1);


  float temp2 = a3tiniTemp(addr2);
  Serial.print("Sensor 2: ");
  Serial.println(temp2);


  lcd.setCursor(0, 1);
  lcd.print("Temp2:");
  lcd.print(temp2);
  delay(2000);
  Serial.println("--------------------");
}



