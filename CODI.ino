​/*
  MASTERMIND
  PROJECTES DE TECNOLOGIA
*/


int red[3] = {255, 0, 0}; //color1
int purple[3] = {255, 0, 255};  //color2
int blue[3] = {0, 65, 255};   //color3
int green[3] = {0, 255, 50};  //color4
int yellow[3] = {255, 255, 0}; //color5
int white[3] = {255, 255, 255}; //color6


int colors_secrets[4] = {0, 0, 0, 0};
int colors_usuari[4] = {0, 0, 0, 0};
int comparativa[4] = {0, 0, 0, 0};

int color_actual[4] = {0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, INPUT);
  tria_colors_secrets();
  pampellugueja();
}
void led1(int red, int green, int blue){
  analogWrite(11, red);
  analogWrite(10, green);
  analogWrite(9, blue);
}
void led2(int red, int green, int blue){
  analogWrite(6, red);
  analogWrite(5, green);
  analogWrite(3, blue);
}
void led3(int red, int green, int blue){
  analogWrite(A0, red);
  analogWrite(A1, green);
  analogWrite(A2, blue);
}
void led4(int red, int green, int blue){
  analogWrite(A3, red);
  analogWrite(A4, green);
  analogWrite(A5, blue);
}

void tria_colors_secrets() {
  randomSeed(analogRead(A6));
  Serial.print("COLORS_SECRETS: ");
  for (int i = 0; i < 4; i++) {
    int num = random(1, 6);
    colors_secrets[i] = num;
    Serial.print(num);
  }
  Serial.println();
}
void pampellugueja() {
  led1(purple[0], purple[1], purple[2]);
  delay(250);
  led2(red[0], red[1], red[2]);
  delay(250);
  led3(yellow[0], yellow[1], yellow[2]);
  delay(250);
  led4(green[0], green[1], green[2]);
  delay(250);
  led1(0, 0, 0);
  delay(250);
  led2(0, 0, 0);
  delay(250);
  led3(0, 0, 0);
  delay(250);
  led4(0, 0, 0);
  delay(250);
}


void demana_valor1() {
  if (comparativa[0] != 2) {
    int i = 0;
    canvia_color1();
    while (i =! 0){
      if (digitalRead(13) == HIGH){
        canvia_color1();
        Serial.println("canvia");
        delay(400);
      }
      else if (digitalRead(12) == HIGH){
        i=1;
        Serial.println("següent led");
        delay(400);
        break;
      }
      
    }
  }
}

void demana_valor2() {
  if (comparativa[1] != 2) {
    int i = 0;
    canvia_color2();
    while (i =! 0){
      if (digitalRead(13) == HIGH){
        canvia_color2();
        Serial.println("canvia");
        delay(400);
      }
      else if (digitalRead(12) == HIGH){
        i=1;
        Serial.println("següent led");
        delay(400);
        break;
      }
    }
  }
}

void demana_valor3() {
  if (comparativa[2] != 2) {
    int i = 0;
    canvia_color3();
    while (i =! 0){
      if (digitalRead(13) == HIGH){
        canvia_color3();
        Serial.println("canvia");
        delay(400);
      }
      else if (digitalRead(12) == HIGH){
        i=1;
        Serial.println("següent led");
        delay(400);
        break;
      }
      
    }
  }
}

void demana_valor4() {
  if (comparativa[3] != 2) {
    int i = 0;
    canvia_color4();
    while (i =! 0){
      if (digitalRead(13) == HIGH){
        canvia_color4();
        Serial.println("canvia");
        delay(400);
      }
      else if (digitalRead(12) == HIGH){
        i=1;
        Serial.println("següent led");
        delay(400);
        break;
      }
      
    }
  }
}

void canvia_color1() {
  if (color_actual[0] == 0 || color_actual[0] == 6  ) {
    Serial.println("red");
    led1(red[0], red[1], red[2]);
    color_actual[0] =  1;
  }
  else if (color_actual[0] == 1) {
    Serial.println("purple");
    led1(purple[0], purple[1], purple[2]);
    color_actual[0] = 2;
  }
  else if (color_actual[0] == 2) {
    Serial.println("blue");
    led1(blue[0], blue[1], blue[2]);
    color_actual[0] = 3;
  }
  else if (color_actual[0] == 3) {
    Serial.println("green");
    led1(green[0], green[1], green[2]);
    color_actual[0] = 4;
  }
  else if (color_actual[0] == 4) {
    Serial.println("yellow");
    led1(yellow[0], yellow[1], yellow[2]);
    color_actual[0] = 5;
  }
  else if (color_actual[0] == 5) {
    Serial.println("white");
    led1(white[0], white[1], white[2]);
    color_actual[0] = 6;
  }

void canvia_color2() {
  if (color_actual[1] == 0 || color_actual[1] == 6  ) {
    Serial.println("red");
    led2(red[0], red[1], red[2]);
    color_actual[1] =  1;
  }
  else if (color_actual[1] == 1) {
    Serial.println("purple");
    led2(purple[0], purple[1], purple[2]);
    color_actual[1] = 2;
  }
  else if (color_actual[1] == 2) {
    Serial.println("blue");
    led2(blue[0], blue[1], blue[2]);
    color_actual[1] = 3;
  }
  else if (color_actual[1] == 3) {
    Serial.println("green");
    led2(green[0], green[1], green[2]);
    color_actual[1] = 4;
  }
  else if (color_actual[1] == 4) {
    Serial.println("yellow");
    led2(yellow[0], yellow[1], yellow[2]);
    color_actual[1] = 5;
  }
  else if (color_actual[1] == 5) {
    Serial.println("white");
    led2(white[0], white[1], white[2]);
    color_actual[1] = 6;
  }
}

void canvia_color3() {
  if (color_actual[2] == 0 || color_actual[2] == 5  ) {
    Serial.println("red");
    led3(red[0], red[1], red[2]);
    color_actual[2] =  1;
  }
  else if (color_actual[2] == 1) {
    Serial.println("purple");
    led3(purple[0], purple[1], purple[2]);
    color_actual[2] = 2;
  }
  else if (color_actual[2] == 2) {
    Serial.println("blue");
    led3(blue[0], blue[1], blue[2]);
    color_actual[2] = 3;
  }
  else if (color_actual[2] == 3) {
    Serial.println("green");
    led3(green[0], green[1], green[2]);
    color_actual[2] = 4;
  }
  else if (color_actual[2] == 4) {
    Serial.println("yellow");
    led3(yellow[0], yellow[1], yellow[2]);
    color_actual[2] = 5;
  }
  else if (color_actual[2] == 5) {
    Serial.println("white");
    led3(white[0], white[1], white[2]);
    color_actual[2] = 6;
  }
}

void canvia_color4() {
  if (color_actual[3] == 0 || color_actual[3] == 5  ) {
    Serial.println("red");
    led4(red[0], red[1], red[2]);
    color_actual[3] =  1;
  }
  else if (color_actual[3] == 1) {
    Serial.println("purple");
    led4(purple[0], purple[1], purple[2]);
    color_actual[3] = 2;
  }
  else if (color_actual[3] == 2) {
    Serial.println("blue");
    led4(blue[0], blue[1], blue[2]);
    color_actual[3] = 3;
  }
  else if (color_actual[3] == 3) {
    Serial.println("green");
    led4(green[0], green[1], green[2]);
    color_actual[3] = 4;
  }
  else if (color_actual[3] == 4) {
    Serial.println("yellow");
    led4(yellow[0], yellow[1], yellow[2]);
    color_actual[3] = 5;
  }
  else if (color_actual[3] == 5) {
    Serial.println("white");
    led4(white[0], white[1], white[2]);
    color_actual[3] = 6;
  }
}

void dona_resultat1(){
  if (comparativa[0] == 0){
    led1(0,0,0);
    color_actual[0] = 0;
  }
  else if (comparativa[0] == 1){
    led1(0,0,0);
    delay(500);
    if (color_actual[0] == 1){
      led1(red[0],red[1],red[2]);
    }
    else if (color_actual[0] == 2){
      led1(purple[0],purple[1],purple[2]);
    }
    else if (color_actual[0] == 3){
      led1(blue[0],blue[1],blue[2]);
    }
    else if (color_actual[0] == 4){
      led1(green[0],green[1],green[2]);
    }
    else if (color_actual[0] == 5){
      led1(yellow[0],yellow[1],yellow[2]);
    }
    else if (color_actual[0] == 6){
      led1(white[0],white[1],white[2]);
    }
    delay(1000);
    led1(0,0,0);
    color_actual[0] = 0;
  }
  
}

void dona_resultat2(){
  if (comparativa[1] == 0){
    led2(0,0,0);
    color_actual[1] = 0;
  }
  else if (comparativa[1] == 1){
    led2(0,0,0);
    delay(500);
    if (color_actual[1] == 1){
      led2(red[0],red[1],red[2]);
    }
    else if (color_actual[1] == 2){
      led2(purple[0],purple[1],purple[2]);
    }
    else if (color_actual[1] == 3){
      led2(blue[0],blue[1],blue[2]);
    }
    else if (color_actual[1] == 4){
      led2(green[0],green[1],green[2]);
    }
    else if (color_actual[1] == 5){
      led2(yellow[0],yellow[1],yellow[2]);
    }
    else if (color_actual[1] == 6){
      led2(white[0],white[1],white[2]);
    }
    delay(1000);
    led2(0,0,0);
    color_actual[1] = 0;
  }
  
}

void dona_resultat3(){
  if (comparativa[2] == 0){
    led3(0,0,0);
    color_actual[2] = 0;
  }
  else if (comparativa[2] == 1){
    led3(0,0,0);
    delay(500);
    if (color_actual[2] == 1){
      led3(red[0],red[1],red[2]);
    }
    else if (color_actual[2] == 2){
      led3(purple[0],purple[1],purple[2]);
    }
    else if (color_actual[2] == 3){
      led3(blue[0],blue[1],blue[2]);
    }
    else if (color_actual[2] == 4){
      led3(green[0],green[1],green[2]);
    }
    else if (color_actual[2] == 5){
      led3(yellow[0],yellow[1],yellow[2]);
    }
    else if (color_actual[2] == 6){
      led3(white[0],white[1],white[2]);
    }
    delay(1000);
    led3(0,0,0);
    color_actual[2] = 0;
  }
  
}

void dona_resultat4(){
  if (comparativa[3] == 0){
    led4(0,0,0);
    color_actual[3] = 0;
  }
  else if (comparativa[3] == 1){
    led4(0,0,0);
    delay(500);
    if (color_actual[3] == 1){
      led4(red[0],red[1],red[2]);
    }
    else if (color_actual[3] == 2){
      led4(purple[0],purple[1],purple[2]);
    }
    else if (color_actual[3] == 3){
      led4(blue[0],blue[1],blue[2]);
    }
    else if (color_actual[3] == 4){
      led4(green[0],green[1],green[2]);
    }
    else if (color_actual[3] == 5){
      led4(yellow[0],yellow[1],yellow[2]);
    }
    else if (color_actual[3] == 6){
      led4(white[0],white[1],white[2]);
    }
    delay(1000);
    led4(0,0,0);
    color_actual[3] = 0;
  }
  
}

void demana_valors(){
 demana_valor1();
 Serial.println("led 1 elegit");
 delay(100);
 demana_valor2();
 Serial.println("led 2 elegit");
 delay(100);
 demana_valor3();
 Serial.println("led 3 elegit");
 delay(100);
 demana_valor4();
 Serial.println("led 4 elegit");
 delay(100);
 Serial.print("COLORS_USUARI: " );
 for (int i = 0; i < 4; i++) {
  colors_usuari[i] = color_actual[i];
  Serial.print(colors_usuari[i]);
  }
  Serial.println();
}

void compara_valors() {
  for (int i = 0; i < 4; i++) {
    if (colors_usuari[i] == colors_secrets[i]) {
      comparativa[i] = 2;
    }
    else if (colors_usuari[i] == colors_secrets[0] || colors_usuari[i] == colors_secrets[1] || colors_usuari[i] == colors_secrets[2] || colors_usuari[i] == colors_secrets[3]) {
      comparativa[i] = 1;
    }
    else {
      comparativa[i] = 0;
    }
  }
}

void dona_resultats(){
   dona_resultat1();
   Serial.println("led 1 correcció donada");
   dona_resultat2();
   Serial.println("led 2 correcció donada");
   dona_resultat3();
   Serial.println("led 3 correcció donada");
   dona_resultat4();
   Serial.println("led 4 correcció donada");
   delay(750);
}

void loop() {
   demana_valors();   //ask the user its prediction
   compara_valors();  //compare values with the secret code
   dona_resultats();  //give results
   }
