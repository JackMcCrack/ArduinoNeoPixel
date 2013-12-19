#include <Adafruit_NeoPixel.h>

#define PIN 6


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5*30, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  int pix=strip.numPixels();
  int pix_amount=pix/10;
  for (int pix_part=0; pix_part<10; pix_part++){
    int pix_offset = pix_amount*pix_part;
    for (int i=0; i<5; i++){
      int pix= random(pix_amount)+pix_offset;
      uint32_t color=strip.Color(random(255)*((pix_part%3)+0),random(255)*((pix_part%3)+1),random(255)*((pix_part%3)+2));
      strip.setPixelColor(pix, color);
        strip.show(); 
    }
    for (int i=0; i<20; i++){
      int pix= random(pix_amount)+pix_offset;
      uint32_t color=strip.Color(0,0,0);
      strip.setPixelColor(pix, color);
        strip.show(); 
    }
  }
}
