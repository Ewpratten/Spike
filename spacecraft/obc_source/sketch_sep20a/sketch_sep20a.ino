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
 * Input:
 *  - Photoresister
 *  - Temprature sensor
 * 
 */



#define P_PHOTORESIST A0
#define P_TX 7
#define P_TXLED 6
#define P_TEMP A1

#define A_FREQ 1300

#define M_LONG 200
#define M_SHORT M_LONG/3


/* Global avg */
long total_light = 0;
int light_readings = 0;

long total_temp = 0;
int temp_readings = 0;

void setup() {
  // Set up Photoresister
  pinMode(P_PHOTORESIST, INPUT);
  pinMode(P_TEMP, INPUT);
  pinMode(P_TX, OUTPUT);
  pinMode(P_TXLED, OUTPUT);


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
  return analogRead(P_TEMP);
}

int getLight(){
  return analogRead(P_PHOTORESIST);
}

void buildTelemString(char *dst, int temp, int light, int avg_temp, int avg_light){

  // START MSG
  dst[0] =  'B';
  dst[1] =  'G';
  dst[2] =  'N';
  dst[3] =  '1';

  // DATA
  // temp
  dst[4] =  '0' + ((temp/100)%10);
  dst[5] =  '0' + ((temp/10)%10);
  dst[6] =  '0' + (temp%10);

  // light
  dst[7] =  '0' + ((light/100)%10);
  dst[8] =  '0' + ((light/10)%10);
  dst[9] =  '0' + (light%10);


  // avg temp
  dst[10] =  '0' + ((avg_temp/100)%10);
  dst[11] =  '0' + ((avg_temp/10)%10);
  dst[12] =  '0' + (avg_temp%10);

  // avg light
  dst[13] =  '0' + ((avg_light/100)%10);
  dst[14] =  '0' + ((avg_light/10)%10);
  dst[15] =  '0' + (avg_light%10);

  // PARITY
  dst[16] =  '0' + (1 + temp + light + avg_temp + avg_light) % 2;

  // END MSG
  dst[17] =  'E';
  dst[18] =  'N';
  dst[19] =  'D';
}

void loop() {

  /* Read sensors */

  // Light
  int light_val = getLight();
  light_val = map(light_val, 0, 1023, 0, 255);

  total_light += light_val;
  light_readings++;

  // Temprature
  int temp_val = getTemprature();
  temp_val = map(temp_val, 0, 1023, 0, 255);

  total_temp += temp_val;
  temp_readings++;
  

  /* Build telem stream */
  char telem_str[20];
  buildTelemString(telem_str, temp_val, light_val, (total_temp / temp_readings), (total_light / light_readings));
  sendTelemData(telem_str);

  // Wait
  delay(5000);

}

/* Begin Morse helpers*/

void handleMorseChr(char input) {
    Serial.println (input);//print the latter saved in the input var
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
void dot () {tone(P_TX,A_FREQ); digitalWrite(P_TXLED, HIGH); delay (M_SHORT); noTone(P_TX); digitalWrite(P_TXLED, LOW); delay (M_SHORT);}//the dot this code make the led on for 300 than off for 300
void dash () {tone(P_TX,A_FREQ); digitalWrite(P_TXLED, HIGH); delay (M_LONG); noTone(P_TX); digitalWrite(P_TXLED, LOW); delay (M_SHORT);}//the dash this code make the led on for 900 than off for 300
void shortspace () {delay(M_LONG);}//space between letters
