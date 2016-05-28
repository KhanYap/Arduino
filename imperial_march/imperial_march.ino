
/* list imperial march on the LCD and shows which note is being played*/
/* verified code works with a motor */
/* To include more functions such as two speakers while runing the LCD.*/ 

// include the library code:
#include <LiquidCrystal.h>

/*initialse pins*/
int speakerPin = 9;

/*the notes to be playe dby segments*/
int length1 = 9; // the number of notes
char* notes1[] = {"a", "a", "a", "f", "cH", "a", "f", "cH", "a", " "}; // a space represents a rest
int beats1[] = { 20, 20, 20, 14, 6, 20, 14, 6, 28 };

int length2 = 9;
char* notes2[] = {"eH", "eH", "eH", "fH", "cH", "gS", "f", "cH", "a", " "}; // a space represents a rest
int beats2[] = { 20, 20, 20, 14, 6, 20, 14, 6, 28 };

int length3 = 9;
char* notes3[] = {"aH", "a", "a", "aH", "gSH", "gH", "fSH", "fH", "fSH", " "}; // a space represents a rest
int beats3[] = { 20, 12, 6, 16, 8, 8, 4, 4, 12 };

int length4 = 7;
char* notes4[] = {"aS", "dSH", "dH", "cSH", "cH", "b", "cH", " "}; // a space represents a rest
int beats4[] = { 10, 16, 8, 8, 4, 4, 12 };

//fifth bit needs to tune
int length5 = 8;
char* notes5[] = {"f", "gS", "f", "cH", "a", "f", "cH", "a", " "}; // a space represents a rest
int beats5[] = { 10, 20, 15, 5, 20, 15, 5, 26 };

/*tempo*/
int tempo = 25;

/*bit to play the correct tone*/
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

/*look up function for each note*/
void playNote(char* note, int duration) 
{
  char* names[] = { "c", "d", "e", "f", "g", "gS", "a", "aS", "b", "cH", "cSH", "dH", "dSH", "eH", "fH", "fSH", "gH","gSH","aH" };
  int tones[] = { 1915, 1700, 1519, 1432, 1278, 1204, 1136, 1098, 1073, 956, 902, 851, 803, 758, 716, 675, 637, 602, 568 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 19; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

//initializing the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(speakerPin, OUTPUT);
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Imperial March: Darth Vader Intro");
}

void loop() {
  
  //scroll th etext to display it first
    // scroll 20 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

delay(200);
lcd.clear();
lcd.print(" Imperial March ");
//short delay before playing
delay(200); 
 
lcd.setCursor(7,1);

  for (int i = 0; i < length1; i++) {
   if (notes1[i] == " ") {
      delay(beats1[i] * tempo); // rest
    } else {
      playNote(notes1[i], beats1[i] * tempo);
    }
    // pause between notes
    delay(tempo*2); 
  }
  
  delay (tempo *6);
   //second bit
   for (int i = 0; i < length2; i++) {
   if (notes2[i] == " ") {
      delay(beats2[i] * tempo); // rest
    } else {
      playNote(notes2[i], beats2[i] * tempo);
    }
    // pause between notes
    delay(tempo*2); 
  }
  
   delay (tempo *6);
   //third bit
   for (int i = 0; i < length3; i++) {
   if (notes3[i] == " ") {
      delay(beats3[i] * tempo); // rest
    } else {
      playNote(notes3[i], beats3[i] * tempo);
    }
    // pause between notes
    delay(tempo*2); 
  }
  
  delay (tempo*10);
  
  //fourth bit
      for (int i = 0; i < length4; i++) {
   if (notes4[i] == " ") {
      delay(beats4[i] * tempo); // rest
    } else {
      playNote(notes4[i], beats4[i] * tempo);
    }
    // pause between notes
    delay(tempo*2); 
  }
  
  delay (tempo*10);
  
  //fifth bit  
  for (int i = 0; i < length5; i++) {
   if (notes5[i] == " ") {
      delay(beats5[i] * tempo); // rest
    } else {
      playNote(notes5[i], beats5[i] * tempo);
    }
    // pause between notes
    delay(tempo*2); 
  }
  
  delay (tempo*40);
}
