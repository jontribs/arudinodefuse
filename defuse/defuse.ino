
 /*
 * This is the Arduino code for TM1637 4 digits display.
 *  * 
 * Written by Ahmad S. for Robojax Video
 * Date: Dec 06, 2017, in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 */

/*
 * Original code from https://github.com/avishorp/TM1637
 * Modified for Robojax video on Dec 06, 2017

 */
#include <Arduino.h>
#include <TM1637Display.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
#define INTERVAL 1000
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
char key;
int time =2;
int start =0;
int codelength =8;
int v1 =0;
int v2 =0;
int v3 =0;
int v4 =0;
int v5 =0;
int v6 =0;
int v7 =0;
int v8 =0;
int seq =0;
long randomNumber;
int repeat = 10;
int timer = 5; 
unsigned long tfa;
const char button_pin =8;
bool press = false;
bool defuse =0;
int seconds;
int minutes;
bool plant =0;
bool kaboom;
int code[8];
byte rowPins[ROWS] = {4,5,6,7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8,9,10,11}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000


TM1637Display display(CLK, DIO);


void setup()
{

  randomSeed(analogRead(9600));
  start=0;
   time = 2;
pinMode(button_pin, INPUT_PULLUP);
  Serial.println(time);
  display.setBrightness(0x0f);

  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);
 for(int i = 0; i < codelength; i++){
   code[i] = random(9);
 }
}

void loop() {
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
   char key = keypad.getKey();

  
    auto seconds = time;
auto minutes = seconds / 60;
auto hours = minutes / 60;
seconds %= 60;
minutes %= 60;
hours %= 24;
  bool currentstate = digitalRead(button_pin);
if (plant == 0) //plant seqence
{
  char key = keypad.getKey();
 display.showNumberDec(code[seq],false,1,0); 
  if (key == code[seq]){
   seq++;
}
 if (seq = 8){
   seq=0;
   plant =1;
 {


 }
 
 

  
   
   //config

  if (millis() > tfa && plant ==1) { //timer every 1s when planted
    tfa = millis() + (unsigned long)INTERVAL;
 display.showNumberDec(seconds,true,2,2);
 display.showNumberDec(minutes,true,1,1);

time = time -1;
}
 }
 }
}
 



 

 


//first input




