#include<Ultrasonic.h>
int Droitdevant, Droitarriere, arriere;
Ultrasonic Uf1(2, 3);
Ultrasonic Uf2(12, 13);
Ultrasonic Uf3(10, 11);
const int speed1 = 9 ;
const int MOTA1 = 8 ;
const int MOTB1 = 7 ;
const int speed2 = 6 ;
const int MOTA2 = 5 ;
const int MOTB2 = 4 ;
char x;
int i, u, v, w;
int r, g, b;
void setup() {
  i = 1;
  pinMode(A0, OUTPUT);///////
  pinMode(A1, OUTPUT);///////////declaration des pin de
  pinMode(A2, OUTPUT);///////////detecteur de couleur
  pinMode(A3, INPUT);////////
  pinMode(A4, OUTPUT);/////////// LED Blue
  pinMode(A5, OUTPUT);/////////// LED Red
  pinMode(A6, OUTPUT);/////////// LED 3
  pinMode(speed1, OUTPUT);// PWM1
  pinMode(MOTA1, OUTPUT);//direction motor 1
  pinMode(MOTB1, OUTPUT);//direction motor 1
  pinMode(speed2, OUTPUT); // PWM2
  pinMode(MOTA2, OUTPUT);//direction motor 2
  pinMode(MOTB2, OUTPUT);//direction motor 2
  Serial.begin(9600);
}
void Blue (){
  analogWrite(A5,0);
  analogWrite(A4,255);
}

void Red (){
  analogWrite(A4,0);
  analogWrite(A5,255);
}

void  ShutLed(){
  analogWrite(A4,0);
  analogWrite(A5,0);
}
void rgb2() { // fonction qui test la couleur
  analogWrite(A0, 255);
  analogWrite(A1, 0);
  analogWrite(A2, 0);
  r = analogRead(A3);
  delay(60);


  analogWrite(A0, 0);
  analogWrite(A1, 255);
  analogWrite(A2, 0);
  g = analogRead(A3);
  delay(60);


  analogWrite(A0, 0);
  analogWrite(A1, 0);
  analogWrite(A2, 255);
  b = analogRead(A3);
  delay(60);

  if ((r >= 40 && r <= 45) && (g >= 55 && g <= 75) && (r >= 40 && r <= 50))
    Serial.println("blue");
  else
    Serial.println("no");
}
void hc06() { // fonction de controler la voiture par votre telephone
  if (Serial.available() ) {
    x = Serial.read();
    // Serial.println(x);
    if (x == 'F') {
      direct();
      avancer2();
    }
    else if (x == 'B') {
      direct();
      reculer2();
    }
    else if (x == 'I') {
      avancer2();
      Droit();
    }
    else if (x == 'G') {
      avancer2();
      gauche();
    }
    else if (x == 'J') {
      reculer2();
      Droit();
    }
    else if (x == 'H') {
      reculer2();
      gauche();
    }
    else if (x == 'R') {
      arret();
      Droit();
    }
    else if (x == 'L') {
      arret();
      gauche();
    }
    else {
      arret();
      direct();
    }
  }
}

void ultra1() { // fonction qui mesure la distance Droitdevant
  Droitdevant = Uf1.read();
}
void ultra2() { // fonction qui mesure la distance Droitarriere
  Droitarriere = Uf2.read();
}
void ultra3() { // fonction qui mesure la distance arriere
  arriere = Uf3.read();
}
void avancer() { // fonction pour avancer avec une vitesse maximal
  analogWrite( speed1 , 255 );
  digitalWrite(MOTA1, LOW);
  digitalWrite(MOTB1, HIGH);
}
void reculer() { // fonction pour reculer avec une vitesse maximal
  analogWrite( speed1 , 255 );
  digitalWrite(MOTA1, HIGH);
  digitalWrite(MOTB1, LOW);
}
void avancer0() { // fonction pour avancer avec une vitesse minimal
  analogWrite( speed1 , 65 );
  digitalWrite(MOTA1, LOW);
  digitalWrite(MOTB1, HIGH);
}
void reculer0() { // fonction pour reculer avec une vitesse minimal
  analogWrite( speed1 , 65 );
  digitalWrite(MOTA1, HIGH);
  digitalWrite(MOTB1, LOW);
}
void avancer1() { // fonction pour avancer avec une vitesse minimal
  analogWrite( speed1 , 85 );
  digitalWrite(MOTA1, LOW);
  digitalWrite(MOTB1, HIGH);
}
void reculer1() { // fonction pour reculer avec une vitesse minimal
  analogWrite( speed1 , 75 );
  digitalWrite(MOTA1, HIGH);
  digitalWrite(MOTB1, LOW);
}
void avancer2() {
  analogWrite( speed1 , 100 );
  digitalWrite(MOTA1, LOW);
  digitalWrite(MOTB1, HIGH);
}
void reculer2() {
  analogWrite( speed1 , 100 );
  digitalWrite(MOTA1, HIGH);
  digitalWrite(MOTB1, LOW);
}
void avancer3() {
  analogWrite( speed1 , 115 );
  digitalWrite(MOTA1, LOW);
  digitalWrite(MOTB1, HIGH);
}
void reculer3() {
  analogWrite( speed1 , 115 );
  digitalWrite(MOTA1, HIGH);
  digitalWrite(MOTB1, LOW);
}
void reculer4() {
  analogWrite( speed1 , 150 );
  digitalWrite(MOTA1, HIGH);
  digitalWrite(MOTB1, LOW);
}
void arret() { // fonction d'arret la voiture
  analogWrite( speed1 , 200 );
  digitalWrite(MOTA1, HIGH);
  digitalWrite(MOTB1, HIGH);
}
void Droit() { // fonction les roule devant en état droit
  analogWrite( speed2 , 255 );
  digitalWrite(MOTA2, LOW);
  digitalWrite(MOTB2, HIGH);
}
void gauche() { // fonction les roule devant en état gauche
  analogWrite( speed2 , 255 );
  digitalWrite(MOTA2, HIGH);
  digitalWrite(MOTB2, LOW);
}
void Droit1() {
  analogWrite( speed2 , 100 );
  digitalWrite(MOTA2, LOW);
  digitalWrite(MOTB2, HIGH);
}
void gauche1() {
  analogWrite( speed2 , 230 );
  digitalWrite(MOTA2, HIGH);
  digitalWrite(MOTB2, LOW);
}
void direct() { // fonction les roule devant en état direct
  analogWrite( speed2 , 0 );
  digitalWrite(MOTA2, HIGH);
  digitalWrite(MOTB2, HIGH);
}
void Read1() {
  ultra1();
}
void Read2() {
  ultra2();
}
void Read3() {
  ultra3();
}
void lire() { // fonction pour lire les mesures qui donnes les ultrasoon
  Read1();
  Read2();
  Read3();
  Serial.print(Droitdevant);
  Serial.print("\t\t");
  Serial.print(Droitarriere);
  Serial.print("\t\t");
  Serial.println(arriere);
}

void vib() { // fonction si la voiture pas encore stationner il fait des vibration droit gauche jusqu'il stationne bien
  ultra1();
  ultra2();
  int o = Droitdevant - Droitarriere;
  Serial.println(o);
  while ( o > 1 ) {
    ultra3();
    if (arriere > 6) {
      while (arriere >= 6  ) {
        gauche();
        reculer0();
        ultra3();
        Serial.println(arriere);
      }
      avancer();
      delay(10);
      arret();
      direct();
      delay(1000);
    }

    else {
      ultra3();
      while (arriere < 10) {
        Droit();
        avancer0();
        ultra3();
        Serial.println(arriere);
      }
      reculer();
      delay(20);
      arret();
      direct();
      delay(1000);
      ultra1();
      ultra2();
    }
    o = Droitdevant - Droitarriere;
    Serial.print("o=");
    Serial.println(o);
  }
}


void finale() { // fonction a une grand duree du temps pour faire la fin des instruction du code
  gauche();
  delay(500);
  direct();
  delay(500);
  Droit();
  delay(500);
  direct();
  delay(1000000);
}

















void loop() {
    // 0000000000000000000000000       Debut               000000000000000000000000000000000000
    delay(3000);
    ultra1();
    ultra2();
    while ( Droitdevant < 12 || Droitarriere < 12 ) {
    avancer1();
    Droit1();
    ultra1();
    ultra2();
    Serial.print(Droitdevant);
    Serial.print("\t\t");
    Serial.println(Droitarriere);

    }
    reculer4();//150
    delay(95);
    arret();
    direct();
    Serial.println("\t  F  i  n    E  t  a  p  e 1");
    delay(3000);





    //11111111111111111111111111111 Debut d'etape 1  1111111111111111111111111111
    // voire l'organigramme
    if ( Droitdevant > 15 && Droitarriere > 15 ) { // la voiture capable de placer dans cette place
    while ( Droitdevant > 15 ) {
      avancer1();
      Droit1();
      ultra1();
      Serial.println(Droitdevant);
    }
    reculer4();
    delay(75);
    arret();
    direct();
    Serial.println("\t  F  i  n    E  t  a  p  e 2");
    delay(3000);
    }


    //22222222222222222 ultrasoon qui en Droit a l'arriere.voir obstacle tourn gauche et arret 2222222222222222222222222
    ultra1();
    Serial.println(Droitdevant);
    while ( Droitdevant < 14 ) {
    avancer1();
    gauche();
    ultra1();
    Serial.println(Droitdevant);
    }
    reculer();
    delay(65);
    direct();
    arret();
    Serial.println("\t  F  i  n    E  t  a  p  e 3");
    delay(3000);




    //333333333333333333333333 ulrasoon arrier.reculer la premier fois Droit voir obstacle et arret 33333333333
    ultra3();
    Serial.println(arriere);
    while (arriere > 25 ) {
    Blue();
    reculer1();
    Droit();
    ultra3();
    Serial.println(arriere);
    }
    avancer();
    delay(65);
    arret();
    direct();
    Serial.println("\t  F  i  n    E  t  a  p  e 4");
    delay(3000);

    // 444444444444444444444 reculer la 2 fois steering wheel a gauche 444444444444444444444444444444444

    ultra3();
    while (arriere > 10) {
    if (arriere > 15){
      Blue;
    }
    else{
     Red();  
    }
    reculer1();
    gauche();
    ultra3();
    }
    avancer();
    delay(55);
    ShutLed();
    direct();
    arret();
    Serial.println("\t  F  i  n    E  t  a  p  e 5");
    delay(3000);
    //      ultra3();
    //    Serial.println(arriere);
    //5555555555555555555 avancer un peu 5555555555555555555555555
    ultra3();
    while (arriere < 12) {
    avancer1();
    Droit();
    ultra3();
    }
    reculer();
    delay(45);
    direct();
    arret();
    Serial.println("\t  F  i  n    E  t  a  p  e 6");
    delay(3000);
    //666666666666 bien placer voir etape 2 dans l'organigramme 666666666666
    vib();
    Serial.println("\t  F  i  n    E  t  a  p  e 7");
    delay(2000);



    // 77777777777777 77777777777777777777777
    ultra3();
    if (arriere <= 4)
    while (arriere <= 7 ) {
      avancer0();
      ultra3();
      Serial.println(arriere);
    }
    else if (arriere > 7) {
    while (arriere > 7 ) {
      reculer0();
      ultra3();
      Serial.println(arriere);
    }
    }
    arret();
    delay(700);
    Serial.println("\t  ************** F  i  n **************** ");
    finale();
}
