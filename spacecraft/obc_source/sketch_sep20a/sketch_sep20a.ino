/**
 * Spike Source code
 * By: Evan Pratten
 * 
 * Sensors:
 *  - Photocell
 *  - Temprature
 *  
 * Output:
 *  - Radio tx
 * 
 */



#define P_PHOTORESIST A0
#define P_TX 7

#define A_FREQ 1400

#define M_SHORT 50
#define M_LONG 200

void setup() {
  // Set up Photoresister
  pinMode(P_PHOTORESIST, INPUT);


  // Connect to host via serial
  Serial.begin(9600);

}

/**
 * Converts a telem string to morse data
 */
void sendTelemData(char data[20]){
  for (int i=0; i < 20; i++) {
     handleMorseChr(data[i]);
  }
}

int getTemprature(){
  return 0;
}

int getLight(){
  return 0;
}

void buildTelemString(char *dst, int temp, int light, int avg_temp, int avg_light){

  // START MSG
  dst[0] =  'B';
  dst[1] =  'G';
  dst[2] =  'N';
  dst[3] =  '1';

  // DATA
  // temp
  dst[4] =  '0';
  dst[5] =  '0';
  dst[6] =  '0';

  // light
  dst[7] =  '0' + ((light/100)%10);
  dst[8] =  '0' + ((light/10)%10);
  dst[9] =  '0' + (light%10);
  
  dst[10] =  '0';
  dst[11] =  '0';
  dst[12] =  '0';
  dst[13] =  '0';
  dst[14] =  '0';
  dst[15] =  '0';

  // PARITY
  dst[16] =  '0';

  // END MSG
  dst[17] =  'E';
  dst[18] =  'N';
  dst[19] =  'D';
}

void loop() {

  // Read sensors
  int light_val = analogRead(P_PHOTORESIST);
  light_val = map(light_val, 0, 1023, 0, 255);

  // Build telem stream
  char telem_str[20];
  buildTelemString(telem_str, 0,light_val,0,0);
  sendTelemData(telem_str);

  // Wait
  delay(5000);

}

/* Begin Morse helpers*/

void handleMorseChr(char input) {
    if (input == 'a' || input == 'A') {lA();}//if the input is a or A go to function lA
    if (input == 'b' || input == 'B') {lB();}//same but with b letter
    if (input == 'c' || input == 'C') {lC();}
    if (input == 'd' || input == 'D') {lD();}
    if (input == 'e' || input == 'E') {lE();}
    if (input == 'f' || input == 'F') {lF();}
    if (input == 'g' || input == 'G') {lG();}
    if (input == 'h' || input == 'H') {lH();}
    if (input == 'i' || input == 'I') {lI();}
    if (input == 'j' || input == 'J') {lJ();}
    if (input == 'k' || input == 'K') {lK();}
    if (input == 'l' || input == 'L') {lL();}
    if (input == 'm' || input == 'M') {lM();}
    if (input == 'n' || input == 'N') {lN();}
    if (input == 'o' || input == 'O') {lO();}
    if (input == 'p' || input == 'P') {lP();}
    if (input == 'q' || input == 'Q') {lQ();}
    if (input == 'r' || input == 'R') {lR();}
    if (input == 's' || input == 'S') {lS();}
    if (input == 't' || input == 'T') {lT();}
    if (input == 'u' || input == 'U') {lU();}
    if (input == 'v' || input == 'V') {lV();}
    if (input == 'w' || input == 'W') {lW();}
    if (input == 'x' || input == 'X') {lX();}
    if (input == 'y' || input == 'Y') {lY();}
    if (input == 'z' || input == 'Z') {lZ();}
    if (input == '1') {n1();}// the numbers
    if (input == '2') {n2();}
    if (input == '3') {n3();}
    if (input == '4') {n4();}
    if (input == '5') {n5();}
    if (input == '6') {n6();}
    if (input == '7') {n7();}
    if (input == '8') {n8();}
    if (input == '9') {n9();}
    if (input == '0') {n0();}
    if (input == ' ') {space();}//the space
    Serial.println (input);//print the latter saved in the input var
}

//fonctions for the letters and the numbers
void lA () {dot();dash();shortspace();}//letter A in morse code!
void lB () {dash();dot();dot();dot();shortspace();}//same for B
void lC () {dash();dot();dash();dot();shortspace();}
void lD () {dash();dot();dot();shortspace();}
void lE () {dot();shortspace();}
void lF () {dot();dot();dash();dot();shortspace();}
void lG () {dash();dash();dot();shortspace();}
void lH () {dot();dot();dot();dot();shortspace();}
void lI () {dot();dot();shortspace();}
void lJ () {dot();dash();dash();dash();shortspace();}
void lK () {dash();dot();dash();shortspace();}
void lL () {dot();dash();dot();dot();shortspace();}
void lM () {dash();dash();shortspace();}
void lN () {dash();dot();shortspace();}
void lO () {dash();dash();dash();shortspace();}
void lP () {dot();dash();dash();dot();shortspace();}
void lQ () {dash();dash();dot();dash();shortspace();}
void lR () {dot();dash();dot();shortspace();}
void lS () {dot();dot();dot();shortspace();}
void lT () {dash();shortspace();}
void lU () {dot();dot();dash();shortspace();}
void lV () {dot();dot();dot();dash();shortspace();}
void lW () {dot();dash();dash();shortspace();}
void lX () {dash();dot();dot();dash();shortspace();}
void lY () {dash();dot();dash();dash();shortspace();}
void lZ () {dash();dash();dot();dot();shortspace();}
void n1 () {dot();dash();dash();dash();dash();shortspace();}//number 1 in morse code
void n2 () {dot();dot();dash();dash();dash();shortspace();}
void n3 () {dot();dot();dot();dash();dash();shortspace();}
void n4 () {dot();dot();dot();dot();dash();shortspace();}
void n5 () {dot();dot();dot();dot();dot();shortspace();}
void n6 () {dash();dot();dot();dot();dot();shortspace();}
void n7 () {dash();dash();dot();dot();dot();shortspace();}
void n8 () {dash();dash();dash();dot();dot();shortspace();}
void n9 () {dash();dash();dash();dash();dot();shortspace();}
void n0 () {dash();dash();dash();dash();dash();shortspace();}
void space () {delay (1200);}//space between words
void dot () {tone(P_TX,A_FREQ); delay (M_SHORT); noTone(P_TX); delay (M_SHORT);}//the dot this code make the led on for 300 than off for 300
void dash () {tone(P_TX,A_FREQ); delay (M_LONG); noTone(P_TX); delay (M_SHORT);}//the dash this code make the led on for 900 than off for 300
void shortspace () {delay(M_LONG);}//space between letters
