/* Sources:
- Adafruit OLED Test: https://learn.adafruit.com/adafruit-128x64-oled-featherwing/arduino-code 
- RGB tips from ESP32io https://esp32io.com/tutorials/esp32-rgb-led 
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);

const int buttonG = 34;
const int buttonR = 39;
int buttonGState = LOW;
int buttonRState = LOW;
int buttonGPresses=0;
int buttonRPresses=0;

//-----------------LEDS-----------------
//-----------------Temperature-----------------
const int ledT_R = 13;
const int ledT_B = 12;
const int ledT_G = 27;
int ledT_R_State = 0;
int ledT_B_State = 0;
int ledT_G_State = 0; 
//-----------------Precipitation-----------------
const int ledP_R = 16;
const int ledP_B = 17;
const int ledP_G = 21;
int ledP_R_State = 0;
int ledP_B_State = 0;
int ledP_G_State = 0; 
//-----------------Wind-----------------
const int ledW_R = 14;
const int ledW_B = 26;
const int ledW_G = 25;
int ledW_R_State = 0;
int ledW_B_State = 0;
int ledW_G_State = 0; 
//-----------------Air-----------------
const int ledA_R = 33;
const int ledA_B = 15;
const int ledA_G = 32;
int ledA_R_State = 0;
int ledA_B_State = 0;
int ledA_G_State = 0; 

unsigned long currentMillis; // how many millis ago did the device start?
const int second = 1000;
const int minute = 60000;
unsigned int elapsedMinutes;

// drawing methods
void drawRoundRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t radius, uint16_t color);
void drawCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);

// SCREEN METHODS
//TODO: Setting for cursor in different places?
// void cursorInMiddle() {display.display();}
//TODO: text wrap something??
//  display.println();   text inserts line break after content
// display.setRotation(R);    // 1=horizontal, 2=vertical right side, 3=flipped, 4=vertical left side

void addVerticalText(String text){
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.setRotation(4);
  display.println(text);
  display.display();
}

void standardSettings(){
  display.setTextSize(1);
  display.setRotation(1);  // turns the screen to default
  display.setCursor(30, 10);
}

void addNormalText(String text){
  standardSettings();
  display.println(text);
  display.display();
}

void clearScreen(){
  display.clearDisplay();
  display.setCursor(5, 20);
  display.display();
}

void addWatch(int elapsedMinutes){
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.setRotation(4);
  display.printf("08:%02i", elapsedMinutes);
}

void textBox(String text){
  standardSettings();
  display.drawRoundRect(25, 25, 100, 35, 5, 1);
  display.setCursor(30, 30);
  display.setTextSize(1);
  display.print(text);
  display.display();
}

void emptyBox(){
  standardSettings();
  display.drawRoundRect(25, 25, 100, 35, 5, 1);
  display.setCursor(30, 30);
  display.setTextSize(1);
  display.display();
}

// TODO: create function for each color change
//void colorChoice(char color){}


// Sets colors for rgbLED, R, B, G values
void setColors(char ledName, int R, int B, int G){
  switch(ledName){
    case 'T':
      digitalWrite(ledT_R, R);
      digitalWrite(ledT_B, B);
      digitalWrite(ledT_G, G);
      break;
    case 'P':
      digitalWrite(ledP_R, R);
      digitalWrite(ledP_B, B);
      digitalWrite(ledP_G, G);
      break;
    case 'W':
      digitalWrite(ledW_R, R);
      digitalWrite(ledW_B, B);
      digitalWrite(ledW_G, G);
      break;
    case 'A':
      digitalWrite(ledA_R, R);
      digitalWrite(ledA_B, B);
      digitalWrite(ledA_G, G);
      break;
  }  
}

void setup() {
  Serial.begin(115200);  // communicates with serial monitor
  Serial.print("Restart\n");
  display.begin(0x3C, true);
  display.display();
  currentMillis = millis();
  elapsedMinutes = round(currentMillis/minute);

  pinMode(buttonG, INPUT);
  pinMode(buttonR, INPUT);
  pinMode(ledT_R, OUTPUT);
  pinMode(ledT_B, OUTPUT);
  pinMode(ledT_G, OUTPUT);
  pinMode(ledP_R, OUTPUT);
  pinMode(ledP_B, OUTPUT);
  pinMode(ledP_G, OUTPUT);
  pinMode(ledW_R, OUTPUT);
  pinMode(ledW_B, OUTPUT);
  pinMode(ledW_G, OUTPUT);
  pinMode(ledA_R, OUTPUT);
  pinMode(ledA_B, OUTPUT);
  pinMode(ledA_G, OUTPUT);

//-----------------SCREEN-----------------
  delay(1000);
  clearScreen();
  display.setTextColor(1);
  addWatch(elapsedMinutes);
  addNormalText("Hei!");

  setColors('T', 1, 0, 0);
  delay(500);
  setColors('P', 0, 1, 0);
  delay(500);
  setColors('W', 0, 0, 1);
  delay(500);
  setColors('A', 1, 1, 1);
  delay(1000);
  clearScreen();
}

void loop() {
  currentMillis = millis();
  elapsedMinutes = floor(currentMillis/minute);
  int min = round(currentMillis/minute);
  
  buttonGState = digitalRead(buttonG);
  buttonRState = digitalRead(buttonR);
  ledT_R_State = digitalRead(ledT_R);
  ledT_B_State = digitalRead(ledT_B);
  ledT_G_State = digitalRead(ledT_G);
  ledP_R_State = digitalRead(ledP_R);
  ledP_B_State = digitalRead(ledP_B);
  ledP_G_State = digitalRead(ledP_G); 
  ledW_R_State = digitalRead(ledW_R);
  ledW_B_State = digitalRead(ledW_B);
  ledW_G_State = digitalRead(ledW_G); 
  ledA_R_State = digitalRead(ledA_R);
  ledA_B_State = digitalRead(ledA_B);
  ledA_G_State = digitalRead(ledA_G); 

  if(buttonGState == HIGH) {
    buttonGPresses++;
    delay(second);
  } else if (buttonRState == HIGH) {
    buttonRPresses++;
    clearScreen();
    addNormalText("Ny sjanse i morgen!");
    setColors('T', 1, 0, 0);
    delay(500);
    setColors('P', 1, 0, 0);
    delay(500);
    setColors('W', 1, 0, 0);
    delay(500);
    setColors('A', 1, 0, 0);
    delay(500);
    delay(5000);
    setColors('T', 0, 0, 0);
    setColors('P', 0, 0, 0);
    setColors('W', 0, 0, 0);
    setColors('A', 0, 0, 0);
    clearScreen();
  } else {
    if (buttonGPresses == 0 && buttonRPresses == 0){
        addWatch(elapsedMinutes);
        addNormalText("Anbefalt i dag:");
        textBox("Sykle");
      while (elapsedMinutes == min && min != 0){
        clearScreen();
        break;
      }
    } else {
      delay(second);
      } 
    }
}
