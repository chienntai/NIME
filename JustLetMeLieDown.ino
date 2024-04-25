/*
  ***** Just Let Me Lie Down *****
  by Chienn Tai - NIME 2024 Spring (instructor: David Rios)
  ***** 8 buttons to MIDI *******

  cheat sheet: 
   Pin to Note(MidiNote): 2=C4(60), 3=D4(62), 4=E4(64), 5=F4(65), 18=G4(67), 19 =A4(69), 20=B4(71), 21=C5(72) 
   Pin to buttons: 2 =A2, 3=A4, 4=D2, 5=F2  | 18=E8, 19=F4, 20=C7, 21=A7 


                          _|  |__
  Buttons 
       =A  =B   =C  =D  =E  =F  =G      
  =1    *   *   *   *   *   *   *
  =2   A2   *   *   D2  *   F2  *
  =3    *   *   *   *   *   *   *
  =4   A4   *   *   *   *   F4  *   ---
  =5    *   *   *   *   *   *   *   ---
  =6    *   *   *   *   *   *   *
  =7   A7   *  C7   *   *   *   *
  =8    *   *   *   *  E8   *   *
  
*/
#include "MIDIUSB.h"

int pin2 =2;  //A2 
int pin3= 3;  //A4
int pin4= 4;  //D2
int pin5= 5;  //F2
int pin18= 18; //E8
int pin19= 19; //F4
int pin20= 20; //C7
int pin21= 21; //A7


int lastState2; //A2
int lastState3; //A4
int lastState4; //D2
int lastState5; //F2
int lastState18; //E8
int lastState19; //F4
int lastState20; //C7
int lastState21; //A7

void setup() {
  Serial.begin(115200);
  //configure pin 2-5 && 18-21 as an input and enable the internal pull-up resistor
  pinMode(pin2, INPUT_PULLUP);
  pinMode(pin3, INPUT_PULLUP);
  pinMode(pin4, INPUT_PULLUP);
  pinMode(pin5, INPUT_PULLUP);
  pinMode(pin18, INPUT_PULLUP);
  pinMode(pin19, INPUT_PULLUP);
  pinMode(pin20, INPUT_PULLUP);
  pinMode(pin21, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  lastState2 = digitalRead(pin2);
  lastState3 = digitalRead (pin3);
  lastState4 = digitalRead (pin4);
  lastState5 = digitalRead (pin5);
  lastState18 = digitalRead (pin18);
  lastState19 = digitalRead (pin19);
  lastState20 = digitalRead (pin20);
  lastState21 = digitalRead (pin21);
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 
  | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}


void loop() {
  //read the pushbutton value into a variable

  int currentState2 = digitalRead(pin2);
  int currentState3 = digitalRead(pin3);
  int currentState4 = digitalRead(pin4);
  int currentState5 = digitalRead(pin5);
  int currentState18 = digitalRead(pin18);
  int currentState19 = digitalRead(pin19);
  int currentState20 = digitalRead(pin20);
  int currentState21 = digitalRead(pin21);
  //print out the value of the pushbutton
 //Serial.println(sensorVal);


  // 2 = C4 ==60
  if (lastState2 != currentState2) {
    if (currentState2 == 0) {
      noteOn(0, 60, 100);
    }
    if (currentState2 == 1) {
      noteOff(0, 60, 60);
    }
    MidiUSB.flush();
    lastState2 = currentState2;
  }
// 3 =D4 ==62 
 if (lastState3 != currentState3) {
    if (currentState3 == 0) {
      noteOn(0, 62, 100);
    }
    if (currentState3 == 1) {
      noteOff(0, 62, 60);
    }
    MidiUSB.flush();
    lastState3 = currentState3;
  }
// 4 =E4 ==64
if (lastState4 != currentState4) {
    if (currentState4 == 0) {
      noteOn(0, 64, 100);
    }
    if (currentState4 == 1) {
      noteOff(0, 64, 60);
    }
    MidiUSB.flush();
    lastState4 = currentState4;
  }

  //5= F4 ==65
if (lastState5 != currentState5) {
    if (currentState5 == 0) {
      noteOn(0, 65, 100);
    }
    if (currentState5 == 1) {
      noteOff(0, 65, 60);
    }
    MidiUSB.flush();
    lastState5 = currentState5;
  }

//18= G4 ==67

if (lastState18 != currentState18) {
    if (currentState18 == 0) {
      noteOn(0, 67, 100);
    }
    if (currentState18 == 1) {
      noteOff(0, 67, 60);
    }
    MidiUSB.flush();
    lastState18 = currentState18;
  }
//19 =A4 ==69
if (lastState19 != currentState19) {
    if (currentState19 == 0) {
      noteOn(0, 69, 100);
    }
    if (currentState19 == 1) {
      noteOff(0, 69, 60);
    }
    MidiUSB.flush();
    lastState19 = currentState19;
  }
//20 =B4 ==71
if (lastState20 != currentState20) {
    if (currentState20 == 0) {
      noteOn(0, 71, 100);
    }
    if (currentState20 == 1) {
      noteOff(0, 71, 60);
    }
    MidiUSB.flush();
    lastState20 = currentState20;
  }
//21= C5 ==72
if (lastState21 != currentState21) {
    if (currentState21 == 0) {
      noteOn(0, 72, 100);
    }
    if (currentState21 == 1) {
      noteOff(0, 72, 60);
    }
    MidiUSB.flush();
    lastState21 = currentState21;
  }
}




