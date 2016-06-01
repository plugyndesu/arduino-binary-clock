/* This is a binary time display for the Arduino Uno board
 *  You must input the time manually (below) each time you
 *  power on the Arduino. 
 *  This program is FOSS
 */

//initial time, put local time here
int hours = 11;
int minutes = 45;

char visibleHours[256];
char visibleMinutes[256];

//initialize functions
void to_binary(int x, char* rev);
void to_binary_minutes(int x, char* rev);

void setup() {
  // put your setup code here, to run once:

  //hours
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);

  //minutes
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);


  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2-13, HIGH);

  to_binary(hours, visibleHours);
  //Serial.print(visibleHours);
  to_binary_minutes(minutes, visibleMinutes);

  if (visibleHours[0] == '1') 
   digitalWrite(10, HIGH);
  else
    digitalWrite(10, LOW);
  if (visibleHours[1] == '1')
    digitalWrite(8, HIGH);
  else
    digitalWrite(8, LOW);
  if (visibleHours[2] == '1')
    digitalWrite(6, HIGH);
  else
    digitalWrite(6, LOW);
  if (visibleHours[3] == '1')
    digitalWrite(4, HIGH);
  else
    digitalWrite(4, LOW);
  if (visibleHours[4] == '1')
    digitalWrite(2, HIGH);
  else
    digitalWrite(2, LOW);


  if (visibleMinutes[0] == '1')
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  if (visibleMinutes[1] == '1')
    digitalWrite(11, HIGH);
  else
    digitalWrite(11, LOW);
  if (visibleMinutes[2] == '1')
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);
  if (visibleMinutes[3] == '1')
    digitalWrite(7, HIGH);
  else
    digitalWrite(7, LOW);
  if (visibleMinutes[4] == '1')
    digitalWrite(5, HIGH);
  else
    digitalWrite(5, LOW);
  if (visibleMinutes[5] == '1')
    digitalWrite(3, HIGH);
  else
    digitalWrite(3, LOW);


  //the actual time logic

  if (minutes != 59) {
    delay(60000);
    minutes++;
  } else {
    delay(60000);
    minutes = 0;
    hours++;
    if (hours == 24)
      hours = 0;
  }
  
}

void to_binary(int x, char* rev) {
  rev[0] = '0';
  rev[1] = '0';
  rev[2] = '0';
  rev[3] = '0';
  rev[4] = '0';
  

  char binary[256];
  int r = (x % 2), q = (x / 2), n = 4, i = 0;

  while (q != 0) {

    if (r == 0)
      *(binary + i) = ('0');
    else
      *(binary + i) = ('1');

    i++;
    r = (q % 2);
    q = (q / 2);

  }
  //*(binary + i) = ('1');

  for (i=0; i<=4; i++) {
    rev[n] = binary[i];
    Serial.print(binary[i]);
    n--;
  }
  rev[5] = '\0';

  if (hours >= 16)
    rev[0] = '1';
  if (hours <= 15) {
    rev[0] = '0';
    rev[1] = '1';
  }
  if (hours <= 7) {
  rev[1] = '0';
  rev[2] = '1';
  }
  if (hours <= 3) {
    rev[2] = '0';
    rev[3] = '1';
  }
  if (hours == 1) {
    rev[3] = '0';
    rev[4] = '1';
  }
  if (hours == 0)
    rev[3] = '0';
 
}

void to_binary_minutes(int x, char* rev) {


  char binary[256];
  int r = (x % 2), q = (x / 2), n = 5, i = 0;

  while (q != 0) {

    if (r == 0)
      *(binary + i) = ('0');
    else
      *(binary + i) = ('1');

    i++;
    r = (q % 2);
    q = (q / 2);

  }
  *(binary + i) = ('1');

  for (i=0; i<=6; i++) {
    rev[n] = binary[i];
    n--;
  }
  rev[7] = '\0';

  if (minutes <= 31)
    rev[0] = '0';
  
  if (minutes <= 15) {
    rev[0] = '0';
    rev[1] = '0';
  }
    if (minutes <= 7) {
    rev[2] = '0';
    rev[3] = '1';
    }
  if (minutes <= 3) {
    rev[3] = '0';
    rev[4] = '1';
  }
  if (minutes == 1) {
    rev[4] = '0';
    rev[5] = '1';
  }
  if (minutes == 0) {
    rev[4] = '0';
    rev[5] = '0';
  }
}