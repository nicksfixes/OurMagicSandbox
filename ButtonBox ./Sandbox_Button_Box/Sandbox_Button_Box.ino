//<---PUT CURSOR HERE BEFORE UPLOADING 
//OR OPEN ANOTHER APP FOR THE CHARACTERS TO GO IN
//e.g. notepad and click on that before upload is done
//THE BOX WILL SEND CHARACTERS 
//IF BUTTONS ARE PRESSED
//THEY WILL COME AT THE CURSOR




#include <Keyboard.h>
bool rButton   = false;
//bool spaceButton   = false;
bool mButton       = false;
bool fButton       = false;
int debounceTimer = 200; //millis
int buttonLedTimer = 500; //millis
int postTimer = 0; //millis

void setup() {
  // put your setup code here, to run once:
  // make pin 2, 3, 4 inputs and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);// Button for Reset (was Islands game = "Spacebar") = "r"
  pinMode(3, OUTPUT);// Button LED for reset  HIGH = ON
  pinMode(4, OUTPUT); //Reset Active LED      HIGH = OFF
  pinMode(5, INPUT_PULLUP);// Button for Sandimal = "f"
  pinMode(6, OUTPUT);// Button LED for Sandimal = "f"             HIGH = ON
  pinMode(7, OUTPUT); //Sandimals Game Active LED                 HIGH = OFF
  pinMode(8, INPUT_PULLUP);// Button for Mothers = "m"
  pinMode(9, OUTPUT);// Button LED for Mothers = "m"              HIGH = ON
  pinMode(10, OUTPUT); //Mothers Game ACtive LED                  HIGH = OFF

  digitalWrite(3, HIGH);// Button LED ON
  digitalWrite(4, LOW); //Reset (Islands Game) is default
  digitalWrite(6, HIGH);// Button LED ON
  digitalWrite(7, HIGH);// Sandimals Game Active LED Off
  digitalWrite(9, HIGH);// Button LED ON
  digitalWrite(10, HIGH);// Mother Game Active LED Off

  Keyboard.begin();  //Enable Keyboard Character output
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  Serial.println("setup ");

}

void loop() {

  //if a button is pressed send appropriate KB char to PC program
  //Flash the Button LED a few times and light the Game Active LED
  //Send an ASCII char for that Game to PC simulating hte Keyboard
  //If one button is detected, the others are ignored until the first is verified
  //Once a button press is verified, and the game updated, wait a short while until looking again.
  //If a button press is not verified, start looking right away

  //This program is not optimised for least code. Brute force and simple is done. No functions.

  //Check for Reset (was Space) Button
  if (digitalRead(2) == LOW) {
    bool rButton = true;// r button pressed
    //bool spaceButton = true;// space button pressed
    delay(debounceTimer);
    if (digitalRead(2) == rButton) {
      // button still pressed

      Keyboard.write(114);     //Send an ASCII 'r',
      Serial.println("r");//resets game but does not  remove animals (yet)
          for (int i = 0; i < 4; i++) {
        digitalWrite(3, LOW);//Button LED  OFF
        delay(buttonLedTimer);
        digitalWrite(3, HIGH);// Button LED  ON
        delay(buttonLedTimer);

      }
      digitalWrite(4, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(10, HIGH);
    }
    rButton = false;
    delay(postTimer) ;
  }

  //Check for "f" Button
  if (digitalRead(5) == LOW) {
    bool fButton = true;// "f" button pressed
    delay(debounceTimer);
    if (digitalRead(5) == fButton) { //button still pressed
      //Send an ASCII 'f)',
      Keyboard.write(102);
      Serial.println("f");
      for (int i = 0; i < 4; i++) {
        digitalWrite(6, LOW);//Button LED  OFF
        delay(buttonLedTimer);
        digitalWrite(6, HIGH);// Button LED  ON
        delay(buttonLedTimer);

      }
      digitalWrite(4, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(10, HIGH);


    }
    fButton = false;
    delay(postTimer) ;
  }

  //Check for "m" Button
  if (digitalRead(8) == LOW) {
    bool mButton = true;// "m" button pressed
    delay(debounceTimer) ;
    if (digitalRead(8) == mButton) { //button still pressed

      Keyboard.write(109);          //Send an ASCII 'm'
      Serial.println("m ");
      for (int i = 0; i < 4; i++) {
        digitalWrite(9, LOW);//Button LED  OFF
        delay(buttonLedTimer);
        digitalWrite(9, HIGH);// Button LED  ON
        delay(buttonLedTimer);

      }
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(10, LOW);
    }
    mButton = false;
    delay(postTimer);
  }

}
