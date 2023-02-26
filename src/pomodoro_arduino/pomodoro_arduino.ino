// include the library code:
#include <LiquidCrystal.h>
#include <math.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int LEDPin = 10;
const int pinA = 6; //ButtonA (PinNumber)
const int pinB = 7; 
int workTime = 0;
int breakTime = workTime/5;
int vA; // LOW = 0 eller FALSE
int vB; // HIGH = 1 eller TRUE (Button is pressed down)
int pvA = 0;
int pvB = 0;

void setup() {
  Serial.begin(9600);
    // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  // setup of LED
  pinMode(LEDPin, OUTPUT);  
  digitalWrite(LEDPin, LOW);
  // set up the switch pin as an input
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
}

//LoopVariables
unsigned long lastMillis, curMillis;

void loop() {
  curMillis = millis(); //This loops millis value
  // check Value of button
  vA = digitalRead(pinA);
  vB = digitalRead(pinB);
  
  lcd.setCursor(0,0);    
  lcd.print("Choose your time");
  int press = 0;

  if (vA == HIGH){
    
    if (vA == LOW){
      press++;
    }

    if (press > 4){
      press = 0;
    }

  // Må ha en måte å endre kun når jeg trykker på knapp

    switch (press){
      case 0:
        lcd.setCursor(0,1);
        lcd.print("");
        lcd.print("20 m");
        workTime = 20;
        delay(2000);
        vA = LOW;
      case 1:
        lcd.setCursor(0,1);
        lcd.print("");
        lcd.print("40 m");
        delay(2000);
        vA = LOW;      
      case 2:
        lcd.setCursor(0,1);
        lcd.print("");
        lcd.print("60 m");
        workTime = 60;
        delay(2000);
        vA = LOW;
      case 3: 
        lcd.setCursor(0,1);
        lcd.print("");
        press = 0;
        vA = LOW;
    }
  }

  if(vB == HIGH){
    lcd.clear(); 
    lcd.print("Starting");
    lcd.setCursor(0,1);
    digitalWrite(LEDPin, HIGH);
    delay(1000);


// skal legge til nedtelling av tid og at det står hvor lang pause det blir 

    switch (workTime) {
      case 0:
        lcd.print("Select time...");
        delay(2000);
        lcd.setCursor(0,1);
        lcd.print("");
        break;
      case 20:
        lcd.print("20 min...");          
        delay(20*1000);
        break;
      case 40:
        lcd.print("40 min...");          
        delay(40*1000);
        break;
      case 60:
        lcd.print("60 min...");          
        delay(60*1000);
        break;
    }
  }
  delay(1000);
}