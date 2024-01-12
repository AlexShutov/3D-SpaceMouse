#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 16

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void init_serial();

void showColor(uint32_t c);
void colorWipe(uint32_t c, uint8_t wait);
void rainbow(uint8_t wait);



// the setup routine runs once when you press reset:
void setup() {

  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
  init_serial();
}


void init_serial() {
  Serial.begin(9600);
   while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // Some example procedures showing how to display to the pixels:
  showColor(strip.Color(100, 50, 70));
}

void showColor(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
