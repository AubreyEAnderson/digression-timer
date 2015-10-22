int segA = 1;   //Display pin 11
int segB = 10;  //Display pin 7
int segC = 4;   //Display pin 4
int segD = 5;   //Display pin 2
int segE = 6;   //Display pin 1
int segF = 3;   //Display pin 10
int segG = 0;   //Display pin 5
int segDP = 11; //Display pin 3
int segs[8] = {segA, segB, segC, segD, segE, segF, segG, segDP};

//          Display pin-> GPIO map
// Display pin: 12    9     8     6
//             ___   ___   ___   ___
//            |   | |   | |   | |   |
//            |___| |___| |___| |___|
//            |   | |   | |   | |   |
//            |___| |___| |___| |___|
int DIGITS[4]= {7,    8,    9,   12}; //DigitalIO pin on Arduino connected to corresponding display pin

int button = 2;

//            1: turn on segment
//            0: turn off segment
//            {A, B, C, D, E, F, G}
int A[]     = {1, 1, 1, 0, 1, 1, 1};
int a[]     = {0, 0, 1, 1, 1, 0, 1};
int B[]     = {1, 1, 1, 1, 1, 1, 1};
int b[]     = {0, 0, 1, 1, 1, 1, 1};
int C[]     = {1, 0, 0, 1, 1, 1, 0};
int c[]     = {0, 0, 0, 1, 1, 0, 1};
int D[]     = {1, 1, 1, 1, 1, 1, 0};
int d[]     = {0, 1, 1, 1, 1, 0, 1};
int E[]     = {1, 0, 0, 1, 1, 1, 1};
int e[]     = {1, 1, 0, 1, 1, 1, 1};
int F[]     = {1, 0, 0, 0, 1, 1, 1};
int G[]     = {1, 0, 1, 1, 1, 1, 1};
int g[]     = {1, 1, 1, 1, 0, 1, 1};
int H[]     = {0, 1, 1, 0, 1, 1, 1};
int h[]     = {0, 0, 1, 0, 1, 1, 1};
int I[]     = {0, 0, 0, 0, 1, 1, 0};
int i[]     = {0, 0, 1, 0, 0, 0, 0};
int J[]     = {0, 1, 1, 1, 1, 0, 0};
int j[]     = {0, 1, 1, 1, 1, 0, 0};
int K[]     = {0, 1, 1, 0, 1, 1, 1};
int L[]     = {0, 0, 0, 1, 1, 1, 0};
int l[]     = {0, 1, 1, 0, 0, 0, 0};
int ll[]    = {0, 1, 1, 0, 1, 1, 0};
int M[]     = {1, 0, 1, 0, 1, 0, 0};
int M1[]    = {1, 1, 0, 0, 1, 1, 0};
int M2[]    = {1, 1, 1, 0, 0, 1, 0};
int m1[]    = {0, 0, 1, 0, 1, 0, 1};
int m2[]    = {0, 0, 1, 0, 1, 0, 1};
int N[]     = {1, 1, 1, 0, 1, 1, 0};
int n[]     = {0, 0, 1, 0, 1, 0, 1};
int O[]     = {1, 1, 1, 1, 1, 1, 1};
int o[]     = {0, 0, 1, 1, 1, 0, 1};
int R[]     = {1, 1, 1, 0, 1, 1, 1};
int r[]     = {0, 0, 0, 0, 1, 0, 1};
int S[]     = {1, 0, 1, 1, 0, 1, 1};
int s[]     = {1, 0, 1, 1, 0, 1, 1};
int T[]     = {1, 1, 1, 0, 0, 0, 0};
int t[]     = {0, 0, 0, 1, 1, 1, 1};
int u[]     = {0, 0, 1, 1, 1, 0, 0};
int w1[]    = {0, 0, 1, 1, 1, 0, 0};
int w2[]    = {0, 0, 1, 1, 1, 0, 0};
int Y[]     = {0, 1, 1, 1, 0, 1, 1};
int blank[] = {0, 0, 0, 0, 0, 0, 0};
int ZERO[]  = {1, 1, 1, 1, 1, 1, 0};
int ONE[]   = {0, 1, 1, 0, 0, 0, 0};
int TWO[]   = {1, 1, 0, 1, 1, 0, 1};
int THREE[] = {1, 1, 1, 1, 0, 0, 1};
int FOUR[]  = {0, 1, 1, 0, 0, 1, 1};
int FIVE[]  = {1, 0, 1, 1, 0, 1, 1};
int SIX[]   = {1, 0, 1, 1, 1, 1, 1};
int SEVEN[] = {1, 1, 1, 0, 0, 0, 0};
int EIGHT[] = {1, 1, 1, 1, 1, 1, 1};
int NINE[]  = {1, 1, 1, 1, 0, 1, 1};

int *NUMBERS[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
unsigned long previousMillis = 0;
unsigned long counter = 0;

unsigned long DIGRESS_TIME = 10;
unsigned long STUDY_TIME = 300; 
unsigned long SCREEN_TIMEOUT = 15;

void displayLetter(int digit, int *letter) {
  displayLetter(digit, letter, false);
}
void displayLetter(int digit, int *letter, boolean DP) { 
  for (int i = 0; i < (sizeof(segs)/sizeof(int))-1; i++) {
    digitalWrite(segs[i], !*(letter+i));
  }
  digitalWrite(segs[(sizeof(segs)/sizeof(int))-1], !DP);

  digitalWrite(DIGITS[digit], HIGH);
  delay(1);
  digitalWrite(DIGITS[digit],LOW);
}

void displayWord(int *statement[]) {
  for (int i = 0; i < sizeof(DIGITS)/sizeof(int); i++) {
    displayLetter(i, statement[i], false);
  }
} 

void scrollSentence(int *sentence[], int sentence_len) {
  while (counter <= sentence_len) {
    for (int i = 0; i < sizeof(DIGITS)/sizeof(int); i++) {
      if (counter+i < sentence_len) {
        displayLetter(i, sentence[counter+i]);
      }
    }
    if (millis() - previousMillis > 1000) {
      previousMillis = millis();
      counter++;
    }

  }
  counter = 0;
}

void setup() {
  //sets each digit to LOW so it does not display
  for (int i = 0; i < sizeof(DIGITS)/sizeof(int); i++) {
    pinMode(DIGITS[i], OUTPUT);
    digitalWrite(DIGITS[i], LOW);
  }

  //sets each segment to HIGH so they do not display
  for (int i = 0; i < sizeof(segs)/sizeof(int); i++) {
    pinMode(segs[i], OUTPUT);
    digitalWrite(segs[i], HIGH);
  } 
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(0, userInput, FALLING);

  pinMode(13, OUTPUT);
}

void displayNumber(int number) {
  displayNumber(number, false);
}

void displayNumber(int number, boolean DP) {
  int blanks=true;
  displayLetter(0, NUMBERS[(int) (number/1000)]);
  displayLetter(1, NUMBERS[(int) (number%1000/100)], DP);
  displayLetter(2, NUMBERS[(int) (number%100/10)]);
  displayLetter(3, NUMBERS[(int) (number%10)]);
}

void countdown(unsigned long seconds, unsigned long start) {
  displayNumber(secondsToMinutesSeconds(seconds-start/1000), true);
}

void countup(unsigned long start) {
  displayNumber(secondsToMinutesSeconds(start/1000), true);
}

int secondsToMinutesSeconds(unsigned long seconds) {
  return (seconds/60*100)+(seconds%60);
}


volatile boolean digressed = false;
volatile unsigned long lastPressed = 0;
volatile unsigned long lastDigression = 0;
void userInput() {
  if (!digressed) {
    lastDigression = millis();
  }
  digressed = true;
  lastPressed = millis();
}

int *blanks[] = {
  blank, blank, blank, blank};

unsigned long timeSince(unsigned long time) {
  return millis()-time;
}

void loop() {
  if (!digressed || (timeSince(lastDigression) > DIGRESS_TIME*1000 && timeSince(lastPressed) > SCREEN_TIMEOUT*1000)) {
    displayWord(blanks);
  } 
  else if (timeSince(lastDigression) < DIGRESS_TIME*1000) {
    countdown(DIGRESS_TIME, timeSince(lastDigression));
  } 
  else {
    countdown(STUDY_TIME, timeSince(lastDigression+DIGRESS_TIME*1000));
  }

  if (timeSince(lastDigression)/1000 > DIGRESS_TIME+STUDY_TIME) {
    digressed = false;
  }
  digitalWrite(13, digressed);
  //    if (digressed && timeSince(lastDigression) < DIGRESS_TIME*1000) {
  //      countdown(DIGRESS_TIME, timeSince(lastDigression));
  //    } else if (digressed && timeSince(lastPressed) < 10*1000) { 
  //      countdown(STUDY_TIME, timeSince(lastDigression+DIGRESS_TIME*1000));
  //    } else if (digressed && timeSince(lastDigression) > (DIGRESS_TIME+STUDY_TIME)*1000) {
  //      digressed = false;
  //    } else if (digressed) {
  //    } else {
  //      displayWord(blanks);
  //    }

}





