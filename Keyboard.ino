uint8_t buf[8] = {0};  // Keyboard Report Buffer: 8 bytes

#define PIN_a 13
#define PIN_s 12
#define PIN_d 11
#define L_Shift 10

#define PIN_j 9 
#define PIN_k 8
#define PIN_l 7
#define R_Shift 6 

//#define SERIAL_DEBUG  // for serial debug: remove //
                        // for actual HID: put //

bool currState_PIN_a = HIGH;
bool currState_PIN_s = HIGH;
bool currState_PIN_d = HIGH;
bool currState_L_Shift = HIGH;

bool currState_PIN_j = HIGH;
bool currState_PIN_k = HIGH;
bool currState_PIN_l = HIGH;
bool currState_R_Shift = HIGH;
          
bool prevState_a = HIGH; 
bool prevState_s = HIGH; 
bool prevState_d = HIGH; 
bool prevState_L_Shift = HIGH;

bool prevState_j = HIGH; 
bool prevState_k = HIGH; 
bool prevState_l = HIGH; 
bool prevState_R_Shift = HIGH;

unsigned long prevTime_a = 0;
unsigned long prevTime_s = 0;
unsigned long prevTime_d = 0;
unsigned long prevTime_L_Shift = 0;

unsigned long prevTime_j = 0;
unsigned long prevTime_k = 0;
unsigned long prevTime_l = 0;
unsigned long prevTime_R_Shift = 0;

unsigned long waitTime_a = 50;
unsigned long waitTime_s = 50;
unsigned long waitTime_d = 50;
unsigned long waitTime_L_Shift = 50;

unsigned long waitTime_j = 50;
unsigned long waitTime_k = 50;
unsigned long waitTime_l = 50;
unsigned long waitTime_R_Shift = 50;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_a, INPUT_PULLUP);
  pinMode(PIN_s, INPUT_PULLUP);
  pinMode(PIN_d, INPUT_PULLUP);
  pinMode(L_Shift, INPUT_PULLUP);

  pinMode(PIN_j, INPUT_PULLUP);
  pinMode(PIN_k, INPUT_PULLUP);
  pinMode(PIN_l, INPUT_PULLUP);
  pinMode(R_Shift, INPUT_PULLUP);
  
  delay(100);
}

void loop() 
{
  checkButton();
}


void checkButton() {

  bool currRead_a = digitalRead(PIN_a);
  bool currRead_s = digitalRead(PIN_s);
  bool currRead_d = digitalRead(PIN_d);
  bool currRead_L_Shift = digitalRead(L_Shift);

  bool currRead_j = digitalRead(PIN_j);
  bool currRead_k = digitalRead(PIN_k);
  bool currRead_l = digitalRead(PIN_l);
  bool currRead_R_Shift = digitalRead(R_Shift);

  if (currRead_a != prevState_a) {
    prevTime_a = millis();
  }
  if (currRead_s != prevState_s) {
    prevTime_s = millis();
  }
  if (currRead_d != prevState_d) {
    prevTime_d = millis();
  }
  if (currRead_L_Shift != prevState_L_Shift) {
    prevTime_L_Shift = millis();
  }

  if (currRead_j != prevState_j) {
    prevTime_a = millis();
  }
  if (currRead_k != prevState_k) {
    prevTime_s = millis();
  }
  if (currRead_l != prevState_l) {
    prevTime_d = millis();
  }
  if (currRead_R_Shift != prevState_R_Shift) {
    prevTime_L_Shift = millis();
  }

/*----------------------a--------------------- */
  if ((millis() - prevTime_a) > waitTime_a) {
    if (currRead_a != currState_PIN_a) {
      currState_PIN_a = currRead_a;
      if (currState_PIN_a == LOW) {
        // Send the code
        buf[2] = 4;    // HID: a key
#ifdef SERIAL_DEBUG
        buf[2] = 'a';     // Serial: a key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }

/*-----------------------s--------------------- */ 
  if ((millis() - prevTime_s) > waitTime_s) {
    if (currRead_s != currState_PIN_s) {
      currState_PIN_s = currRead_s;
      if (currState_PIN_s == LOW) {
        // Send the code
        buf[2] = 22;   // HID: s key
#ifdef SERIAL_DEBUG
        buf[2] = 's';   // Serial: A key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }

/*----------------------d---------------------- */  
  if ((millis() - prevTime_d) > waitTime_d) {
    if (currRead_d != currState_PIN_d) {
      currState_PIN_d = currRead_d;
      if (currState_PIN_d == LOW) {
        // Send the code
        buf[2] = 7;    // HID: d key
#ifdef SERIAL_DEBUG
        buf[2] = 'd';     // Serial: d key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }

/*----------------------L_Shift---------------------- */
  if ((millis() - prevTime_L_Shift) > waitTime_L_Shift) {
    if (currRead_L_Shift != currState_L_Shift) {
      currState_L_Shift = currRead_L_Shift;
      if (currState_L_Shift == LOW) {
        // Send the code
        buf[2] = 225;   // HID: L_Shift key
#ifdef SERIAL_DEBUG        
        buf[2] = 'L';   // Serial: L_Shift key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }

/*---------------------j----------------------- */
    if ((millis() - prevTime_j) > waitTime_j) {
    if (currRead_j != currState_PIN_j) {
      currState_PIN_j = currRead_j;
      if (currState_PIN_j == LOW) {
        // Send the code
        buf[2] = 13;    // HID: j key
#ifdef SERIAL_DEBUG
        buf[2] = 'j';     // Serial: j key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }

/*-----------------------k--------------------- */
    if ((millis() - prevTime_k) > waitTime_k) {
    if (currRead_k != currState_PIN_k) {
      currState_PIN_k = currRead_k;
      if (currState_PIN_k == LOW) {
        // Send the code
        buf[2] = 14;    // HID: k key
#ifdef SERIAL_DEBUG
        buf[2] = 'k';     // Serial: k key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }

/*-----------------------l--------------------- */
    if ((millis() - prevTime_l) > waitTime_l) {
    if (currRead_l != currState_PIN_l) {
      currState_PIN_l = currRead_l;
      if (currState_PIN_l == LOW) {
        // Send the code
        buf[2] = 15;    // HID: l key
#ifdef SERIAL_DEBUG
        buf[2] = 'l';     // Serial: l key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }

/*------------------------R_Shift-------------------- */
    if ((millis() - prevTime_R_Shift) > waitTime_R_Shift) {
    if (currRead_R_Shift != currState_R_Shift) {
      currState_R_Shift = currRead_R_Shift;
      if (currState_R_Shift == LOW) {
        // Send the code
        buf[2] = 229;    // HID: R_Shift key
#ifdef SERIAL_DEBUG
        buf[2] = 'R';     // Serial: R_Shift key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  

  prevState_a = currRead_a;
  prevState_s = currRead_s;
  prevState_d = currRead_d;
  prevState_L_Shift = currRead_L_Shift;

  prevState_j = currRead_j;
  prevState_k = currRead_k;
  prevState_l = currRead_l;
  prevState_R_Shift = currRead_R_Shift;

}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}
