#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "bitmap/happy.h"
#include "bitmap/sad.h"
// #include "bitmap/on.h"
// #include "bitmap/lain.h"

#define SCREEN_I2C_ADDR 0x3C 
#define SCREEN_WIDTH 128    
#define SCREEN_HEIGHT 64     
#define OLED_RST_PIN -1      

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST_PIN);

#define FRAME_DELAY (42)

#define LED_BIRU 3
#define LED_MERAH 5
void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();

  display.display(); 
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR);

  pinMode(LED_BIRU, OUTPUT); 
  pinMode(LED_MERAH, OUTPUT);
}
int frame = 0;
void loop() {
  // nampilin gambar happy
  display.clearDisplay();
  display.drawBitmap(32, 0, happy[frame], WIDTH_HAPPY, HEIGHT_HAPPY, 1);
  display.display();
  frame = (frame + 1) % COUNT_HAPPY;
  delay(FRAME_DELAY);

  // nampilin gambar sad
  display.clearDisplay();
  display.drawBitmap(32, 0, sad[frame], WIDTH_SAD, HEIGHT_SAD, 1);
  display.display();
  frame = (frame + 1) % COUNT_SAD;
  delay(FRAME_DELAY);
}
