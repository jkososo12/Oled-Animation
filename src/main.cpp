#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "../src/bitmap/happy.h"
#include "../src/bitmap/sad.h"
#include "../src/bitmap/confused.h"

#define SCREEN_I2C_ADDR 0x3C 
#define SCREEN_WIDTH 128    
#define SCREEN_HEIGHT 64     
#define OLED_RST_PIN -1      

#define BLUE_LED 2
#define RED_LED 4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST_PIN);

void setup() {
  Serial.begin(9600);

  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Berhenti di sini jika gagal
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  // Contoh: atur nilai LED secara manual (untuk demo)
  digitalWrite(BLUE_LED, LOW);  // Set LED biru ON
  digitalWrite(RED_LED, HIGH);    // Set LED merah OFF

  bool blueState = digitalRead(BLUE_LED);
  bool redState = digitalRead(RED_LED);

  display.clearDisplay(); // Selalu bersihkan display dulu

  if (blueState && redState) {
    display.drawBitmap(0, 0, confused, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  } else if (redState) {
    display.drawBitmap(0, 0, senyum, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  } else if (!blueState && !redState) {
    // Jangan tampilkan gambar apa-apa (kosongkan layar)
    display.clearDisplay();
  } else {
    display.drawBitmap(0, 0, sad, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  }

  display.display();  
  delay(2000); // Tampilkan gambar selama 2 detik
}

