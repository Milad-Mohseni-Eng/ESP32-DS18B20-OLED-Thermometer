// ======================================================
// ESP32 Digital Thermometer with OLED Display
// Sensor : DS18B20 (OneWire)
// Display: OLED SSD1306 (I2C)
// Board  : ESP32 (30-pin)
// ======================================================

// ---------- Libraries ----------
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------- Pin Definitions ----------
#define ONE_WIRE_BUS 4      // DS18B20 data pin
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// ---------- OLED Configuration ----------
#define OLED_RESET -1       // No reset pin used
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ---------- DS18B20 Setup ----------
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// ---------- Timing ----------
unsigned long lastReadTime = 0;
const unsigned long readInterval = 1000; // 1 second

void setup() {
  Serial.begin(115200);

  // Initialize temperature sensor
  sensors.begin();

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed");
    while (true); // Stop execution
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Startup message
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32 Thermometer");
  display.println("----------------");
  display.println("DS18B20 Sensor");
  display.display();

  delay(1500);
}

void loop() {
  unsigned long currentTime = millis();

  // Read temperature every 1 second (non-blocking)
  if (currentTime - lastReadTime >= readInterval) {
    lastReadTime = currentTime;

    sensors.requestTemperatures();
    float temperatureC = sensors.getTempCByIndex(0);

    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" C");

    // Update OLED
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Temperature Monitor");
    display.println("------------------");

    display.setTextSize(2);
    display.setCursor(0, 25);

    if (temperatureC == DEVICE_DISCONNECTED_C) {
      display.println("Sensor Error");
    } else {
      display.print(temperatureC, 1);
      display.print(" C");
    }

    display.display();
  }
}