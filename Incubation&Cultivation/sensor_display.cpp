#include "DHT.h"
#include <Adafruit_SSD1306.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(4);

void setup() {
 Serial.begin(9600);
 dht.begin();
 display.begin(SSD1306_I2C_ADDRESS, OLED_RESET);
 display.display();
 delay(2000);
 display.clearDisplay();
}

void loop() {
 float humidity = dht.readHumidity();
 float temp = dht.readTemperature();

 display.clearDisplay();
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(0, 0);
 display.print("Temperature: ");
 display.print(temp);
 display.print("C");
 display.setCursor(0, 10);
 display.print("Humidity: ");
 display.print(humidity);
 display.print("%");
 display.display();

 delay(2000);
}
