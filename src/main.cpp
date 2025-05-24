#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "happy.h"

#define SCREEN_I2C_ADDR 0x3C 
#define SCREEN_WIDTH 128    
#define SCREEN_HEIGHT 64     
#define OLED_RST_PIN -1      

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST_PIN);

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();

  display.display(); 
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR);
  display.clearDisplay();
  display.drawBitmap(0, 0, epd_bitmap_happy_face_clip_art_smiley_face_clipart_3_clipartcow, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display.display();
  delay(2000); // Display the image for 2 seconds
}
int frame = 0;
void loop() {
    

}
