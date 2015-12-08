//#include <TimerOne.h>
#include <Wire.h>
#include "RTClib.h"
#include "SevSeg.h"

RTC_DS1307 RTC;


SevSeg sevseg; //Instantiate a seven segment object

SevSeg sevseg2;

/*
 * Top Row:    1 A F 2 3 B
   Bottom Row: E D P C G 4
 *
 */
int a = 3;
int b = 7;
int c = 11;
int d = 9;
int e = 8;
int f = 4;
int g = 12;
int dot = 10;
//digits

int d4 = 13;
int d2 = 6;
int d3 = 5;
int d1 = 2;



void setup() {
  byte numDigits = 4;
  byte digitPins[] = {d1, d2, d3, d4};
  byte segmentPins[] = {a, b, c, d, e, f, g, dot};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  //sevseg.setBrightness(10);

  Serial.begin(9600);
  Wire.begin();
  RTC.begin();

  if (!RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //RTC.adjust(DateTime(__DATE__, __TIME__));

  } else {
    Serial.println("RTC is  running!");
  //  RTC.adjust(DateTime(2015, 12, 6, 0, 28, 30));
  }
 //  RTC.adjust(DateTime(2015, 12, 6, 0, 34, 30));
  //  RTC.adjust(DateTime(2015, 12, 5, 17, 4, 2));


  //Timer1.initialize(1000000);
  //Timer1.attachInterrupt(next); // blinkLED to run every 0.15 seconds



}

int n = 0;
void loop() {


  DateTime now = RTC.now();
  float t = now.hour() + now.minute() / 100.0;
  Serial.println(t);
  sevseg.setNumber(t, 2); // Displays '3.141'
  sevseg.refreshDisplay();

  //DateTime now = RTC.now();
  /// Serial.print(now.year(), DEC);
}

void next() {
  n++;
  //  DateTime now = RTC.now();




}


