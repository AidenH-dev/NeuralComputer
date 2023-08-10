# Incubation Chamber 
> (Based on The Thought Emporiums [Meatcubator](https://github.com/thethoughtemporium/meatcubator#parts-list))\
\
The goal is to sutain the optimal conditions that are condusive of mammalian cell growth. This means consistantly regulating and monitoring the CO<sub>2</sub> , humidity and temperature of the container.

## Parts 
<img width="307" alt="image" src="https://github.com/AidenH-dev/NeroComputer/assets/109930537/23f2e404-c046-48f1-a07b-87beff714a5c">\
<em>Incubator [**`amazon`**](https://www.amazon.com/dp/B0C7KHHYNT/ref=sspa_dk_detail_2?pd_rd_i=B0C7KHHYNT&pd_rd_w=7b65S&content-id=amzn1.sym.eb7c1ac5-7c51-4df5-ba34-ca810f1f119a&pf_rd_p=eb7c1ac5-7c51-4df5-ba34-ca810f1f119a&pf_rd_r=W4D2CJYHTA6Z1E2CW89A&pd_rd_wg=TLYaf&pd_rd_r=80d2b376-849f-40c6-9d69-92b55ceebc14&s=industrial&sp_csd=d2lkZ2V0TmFtZT1zcF9kZXRhaWw&th=1)</em>
> This will serve as the base container and heating controller.

<br><br>

<img width="300" alt="image" src="https://github.com/AidenH-dev/NeroComputer/assets/109930537/a274f7d4-6193-4dc8-83c7-d71a742be5d7">\
<em>Humidity & Temp Sensor [**`amazon`**](https://www.amazon.com/dp/B089N2XHTL?psc=1&ref=ppx_yo2ov_dt_b_product_details)</em>
> Extra sensors to monitor the resting temperature and humidity of the chamber.

<br><br>

<img width="300" alt="image" src="https://github.com/AidenH-dev/NeuralComputer/assets/109930537/cef0e793-4ff4-4588-9263-a3f6aea64ad7">\
<em> Adafruit SCD-30 - NDIR CO2 DHT Sensor [**`adafruit`**](https://www.adafruit.com/product/4867)</em>
> To monitor the CO<sub>2</sub> supplied to the chamber and confirm the resting temperature and humidity.

<br><br>

<img width="300" alt="image" src="https://github.com/AidenH-dev/NeroComputer/assets/109930537/2ece79c3-efb0-4c26-868f-4c2b6de8ea4e">\
<em>Toggle Swtich [**`amazon`**](https://www.amazon.com/gp/product/B07VQFKZ22/ref=ox_sc_act_title_1?smid=AGOSLUO29ZUJ2&th=1)</em>
> To swtich on and off the CO<sub>2</sub> supply to the chamber.

<br><br>

<img width="300" alt="image" src="https://github.com/AidenH-dev/NeroComputer/assets/109930537/0bf9daed-3ae8-49cb-a278-037fcfcdf389">\
<em>OLED Display [**`adafruit`**](https://www.adafruit.com/product/4650)</em>
> To display sutff :P 

<br><br>

<img width="300" alt="image" src="https://github.com/AidenH-dev/NeuralComputer/assets/109930537/46a7e27c-ef4d-4a83-83c8-616730c8669a">\
<em>Raspberry Pi Pico Microcontroller [**`amazon`**](https://www.amazon.com/Pico-Raspberry-Pre-Soldered-Dual-core-Processor/dp/B0BK9W4H2Q/ref=sr_1_4?keywords=raspberry+pi+pico&qid=1691511298&sr=8-4)</em>
> This is the central controller of the system. It will log all the information gathered by the sensors and use that to notify about the temperature within the chamber and regulate the CO<sub>2</sub> added to the chamber. 

<br><br>
_Parts that require more research_
- [ ] 60L SodaStream CO2 Canister. 
- [ ] CO2 Regulator. 
- [ ] 12V Solenoid Valve. 
- [ ] Tubing and 0.2um filter.
- [ ] Flow valve
- [ ] System Power Supply



## Getting Started 
> The total process will be broken down into individual managable goals 

### Step 1 - Modifying the Incubator
Integrating the CO<sub>2</sub> and temp sensor. As well as testing the best locations withing the chamber to place the sensors and coding the basic logging and notifications into the microcontroller that will serve as the triggers to manage the CO<sub>2</sub> levels.  

1. Pico CO<sub>2</sub> Sensor & OLED circuit (TECHINCALLY RUNS AN ERROR BC OF ONLINE SIM) (MISSING CARBON SENSOR)\
   <img width="315" alt="image" src="https://github.com/AidenH-dev/NeuralComputer/assets/109930537/574e4f76-009d-436c-b171-fdb50f0b2da0">
   ```cpp
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
   ```
   


### Step 2 - Adding CO<sub>2</sub> Control
Hooking up the CO<sub>2</sub> canister and the relevant regulators and solenoid valvs. Then connecting it to the Raspberry Pico.

### Step 3 - Logging and Wifi Connection (Optional)
Adding functionality to the raspery pi that sends a log over wifi to an aws server that stores the sensor information in a postgresql database and then displays it through a private auth0 protected next js webapp. 



# Positive Laminar Flow Hood 
>(To be placed in different folder for the sanitation parts of the project)

