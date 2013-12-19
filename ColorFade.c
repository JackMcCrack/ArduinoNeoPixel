#include <Adafruit_NeoPixel.h>

#define PIN 6

const int fade = 80;  // steps of fading
const int leds = 150; // Number of LEDs

int fade_step[leds]; // state of fading
boolean fade_in[leds]; //direction of fading
int fade_r[leds]; //red
int fade_g[leds]; //green
int fade_b[leds]; //blue

Adafruit_NeoPixel strip = Adafruit_NeoPixel(leds, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  for (int i=0; i<leds; i++){
    fade_step[i]=0;
    fade_in[i]=false;
  }

}


void loop() {
  for (int i=0; i<leds; i++){ 
    if (fade_step[i] > 0){
      fadeled(i);
    }
    else if (fade_step[i] <= 0){
      // set color and start fading
      if (random(1000) < 3 ){
        fade_r[i]=random(100); //red max 255  
        fade_g[i]=random(100); //green max 255
        fade_b[i]=random(100); //blue max 255
        fade_step[i] = 1;
        fade_in[i] = true;
      }
    }
  }
  strip.show();
  delay(10);
}


void fadeled(int led) {
  // fade to color and back to black
  strip.setPixelColor(led, strip.Color((fade_step[led]*fade_r[led]/fade)%255,(fade_step[led]*fade_g[led]/fade)%255,(fade_step[led]*fade_b[led]/fade)%255));  
  if (fade_step[led]>= fade){
    // change fade direction
    fade_in[led]= false;
  }

  if (fade_in[led]){
    fade_step[led]++;
  }
  else {
    fade_step[led]--;
  }

  if (fade_step[led] == 0){
    // last fade step to off/black
    strip.setPixelColor(led, strip.Color(0, 0, 0));
  }

}

