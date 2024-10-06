const int ledPins[4] = {2, 3, 4, 5};    // пинови на ардуино на кои се поврзани LEDs
const int addButton = 7;                // пин на кој е поврзано копчето
int counter = 0;                        // променлива која го чува тековниот број
int prevCounter = 0;                    // променлива за да се следи претходниот број
bool countUp = true;                    // променлива која кажува дали броиме нагоре или надолу

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);        // дефинирање на сите LED диоди како излези
  }

  pinMode(addButton, INPUT);            // дефинирање на копчето како влез
}

void loop() {
  if (digitalRead(addButton) == LOW) {   // доколку копчето е притиснато
    if (counter < 15 && countUp) {       // ако бројачот е помал од 15 и броеме нагоре
      counter++;                         // зголеми го бројачот за 1
      if(counter >= 15) countUp = false; // ако бројачот е 15, смени го правецот на броење
      delay(200);                        // одложување за да се спречи пребрзо броење
    }
    else if (counter > 0 && !countUp) {  // ако бројачот е поголем од 0 и броеме надолу
      counter--;                         // намали го бројачот за 1
      if(counter <= 0) countUp = true;   // ако бројачот е 0, смени го правецот на броење
      delay(200);                        // одложување за да се спречи пребрзо броење
    } 

    while (digitalRead(addButton) == LOW) {}  // чекање додека копчето е притиснато
  }
  
  if(counter != prevCounter) {           // ако има промена на бројот
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], (counter >> i) & 0x01); // прикажување на новиот број бинарно
    }
    prevCounter = counter;               // ажурирање на претходниот број
  }
}
