#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    4
#define NUM_COLORS  6

#define CORRECCIO_PIN 6

word colors[NUM_COLORS] = {CRGB::Red, CRGB::Purple, CRGB::Blue, CRGB::Green, CRGB::Yellow, CRGB::White};

CRGB leds[NUM_LEDS];
CRGB leds_correccio[CORRECCIO_PIN];

int colors_secrets[4] = {0, 0, 0, 0};
int colors_usuari[4] = {0, 0, 0, 0};
int comparativa[4] = {0, 0, 0, 0};


int color_actual[4] = {0, 0, 0, 0};


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(5);
}

void tria_colors_secrets() {
  randomSeed(analogRead(A6));
  Serial.print("COLORS_SECRETS: ");
  for (int i = 0; i < NUM_COLORS; i++) {
    int num = random(1, 6);
    colors_secrets[i] = num;
    Serial.print(num);
  }
  Serial.println();
}

void pampellugueja() {
  leds[0] = CRGB::DeepSkyBlue;
  FastLED.show();
  delay(250);
  leds[1] = CRGB::Purple;
  FastLED.show();
  delay(250);
  leds[2] = CRGB::HotPink;
  FastLED.show();
  delay(250);
  leds[3] = CRGB::Red;
  FastLED.show();
  delay(500);
  leds[3] = CRGB::Black;
  FastLED.show();
  delay(250);
  leds[2] = CRGB::Black;
  FastLED.show();
  delay(250);
  leds[1] = CRGB::Black;
  FastLED.show();
  delay(250);
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(250);



}

void demana_valor(int led) {
    if (comparativa[led] != 2) {
        bool triant;
        canvia_color(led);
        while (triant) {
            if (digitalRead(13) == HIGH) {
                canvia_color(led);
                Serial.println("canvia");
                delay(400);
             
      }
            else if (digitalRead(12) == HIGH) {
                triant = false;
                Serial.println("següent led");
                delay(400);
                break;
             
      }
            
         
    }
     
  }
}

void canvia_color(int led) {
    if (color_actual[led] == 0 || color_actual[led] == NUM_COLORS ) {
        Serial.println("red");
        leds[led] = colors[0];
        color_actual[led] =  1;
     
  }
    else if (color_actual[led] == 1) {
        Serial.println("purple");
        leds[led] = colors[1];
        color_actual[led] = 2;
     
  }
    else if (color_actual[led] == 2) {
        Serial.println("blue");
        leds[led] = colors[2];
        color_actual[led] = 3;
     
  }
    else if (color_actual[led] == 3) {
        Serial.println("green");
        leds[led] = colors[3];
        color_actual[led] = 4;
     
  }
    else if (color_actual[led] == 4) {
        Serial.println("yellow");
        leds[led] = colors[4];
        color_actual[led] = 5;
     
  }
  else if (color_actual[led] == 5) {
        Serial.println("white");
        leds[led] = colors[5];
        color_actual[led] = 6;
     
  }
}

void dona_resultat(int led) {
    if (comparativa[led] == 0) {
        led1(0, 0, 0);
        color_actual[0] = 0;
     
  }
    else if (comparativa[0] == 1) {
        led1(0, 0, 0);
        delay(500);
        if (color_actual[0] == 1) {
            led1(red[0], red[1], red[2]);
         
    }
        else if (color_actual[0] == 2) {
            led1(purple[0], purple[1], purple[2]);
         
    }
        else if (color_actual[0] == 3) {
            led1(blue[0], blue[1], blue[2]);
         
    }
        else if (color_actual[0] == 4) {
            led1(green[0], green[1], green[2]);
         
    }
        else if (color_actual[0] == 5) {
            led1(yellow[0], yellow[1], yellow[2]);
    }
    else if (color_actual[0] == 6) {
            led1(white[0], white[1], white[2]);

    }
        delay(1000);
        led1(0, 0, 0);
        color_actual[0] = 0;
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  tria_colors_secrets();
  pampellugueja();
}
