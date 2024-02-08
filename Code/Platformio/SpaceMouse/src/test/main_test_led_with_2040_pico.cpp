#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include <OneButton.h>
// todo extract interface
#include <Tlv493d.h>
#include <Adafruit_MMC56x3.h>

#include <SimpleKalmanFilter.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 16

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size

// лампочка
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// сенсор
Tlv493d Tlv493dMagnetic3DSensor = Tlv493d();
Adafruit_MMC5603 mag = Adafruit_MMC5603(12345);

// фильтр мышки
SimpleKalmanFilter xFilter(1, 1, 0.2), yFilter(1, 1, 0.2), zFilter(1, 1, 0.2);

// Кнопки, нужно будет посмотреть, куда точно припаяю
OneButton button1(27, true);
OneButton button2(24, true);

void init_serial();

void showColor(uint32_t c);
void colorWipe(uint32_t c, uint8_t wait);
void rainbow(uint8_t wait);



// the setup routine runs once when you press reset:
void setup_backup() {

  strip.begin();
  strip.setBrightness(255);
  strip.show(); // Initialize all pixels to 'off'
//   init_serial();
}


void init_serial() {
  Serial.begin(9600);
   while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
}


// the loop routine runs over and over again forever:
void loop_backup() {
  // Some example procedures showing how to display to the pixels:
  strip.clear();
  showColor(strip.Color(255, 0, 0));
  strip.show();
  delay(100);

  showColor(strip.Color(0, 0, 255));
  delay(100);
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
