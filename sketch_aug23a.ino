#include <TM1637.h>

/* Author: Ugur Coskun */
/* The aim of the project is showing relay number on 7-segment display which relay is activated with controlling switch button. */
/* Digital Pin Configurations  */
#define role1 2
#define role2 3
#define UP 9
#define DOWN 10
#define DUAL 11


/* Initializations */
bool up1;
bool down1;
bool dual1;

int CLK = 4;
int DIO = 5;

/* Defining 7-segment variables */
TM1637 tm(CLK,DIO);

void setup() {
  /* Variables assigning as outputs and inputs */
  pinMode(role1,OUTPUT);
  pinMode(role2,OUTPUT);
  pinMode(UP,INPUT);
  pinMode(DOWN,INPUT);
  pinMode(DUAL,INPUT);
  
  tm.init();
  tm.set(2);
}

void loop() {
/* This part takes switch position and assign to variables */
up1 = digitalRead(UP);
down1 = digitalRead(DOWN);
dual1 = digitalRead(DUAL);

/* If switch button pressed variables are high. And if condition satisfied. */
if(up1 == HIGH){
digitalWrite(role1,HIGH);// Activates relay

/* Shows relay number on 7-segment display */
  tm.display(0,0);
  tm.display(1,1);
  tm.point(1);
  tm.display(2,0);
  tm.display(3,0);

 delay(2000); // Waits 2 seceond
 
}

else if(up1 == LOW){

digitalWrite(role1,LOW);


 tm.display(0,0);
  tm.display(1,0);
  tm.point(1);
  tm.display(2,0);
  tm.display(3,0);
  delay(2000);
 }

if(dual1 == HIGH){

  digitalWrite(role1,HIGH);

digitalWrite(role2,HIGH);

  tm.display(0,0);
  tm.display(1,1);
  tm.point(1);
  tm.display(2,0);
  tm.display(3,2);
  delay(500);
  }
 else if (dual1 == LOW) {

  digitalWrite(role1,LOW);

digitalWrite(role2,LOW);

  tm.display(0,0);
  tm.display(1,0);
  tm.point(1);
  tm.display(2,0);
  tm.display(3,0);
  delay(500);
  }
   
else if(down1 == HIGH){
digitalWrite(role2,HIGH);

tm.display(0,0);
  tm.display(1,0);
  tm.point(1);
  tm.display(2,0);
  tm.display(3,2);
  delay(2000);
}
  else if(down1 == LOW){     
digitalWrite(role2,LOW);

  tm.display(0,0);
  tm.display(1,0);
  tm.point(1);
  tm.display(2,0);
  tm.display(3,0);
delay(2000);
}

  }
