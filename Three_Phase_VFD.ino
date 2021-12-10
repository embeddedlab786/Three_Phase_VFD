int AA1=3;
int AA2=5;
int BB1=6;
int BB2=9;
int CC1=10;
int CC2=11;

int fase=1;

int tiempo=100;
unsigned long previousMillis = 0; 

int Stop=0;

int val = A0; 

void setup() {

  Serial.begin(9600);
  pinMode(AA1,OUTPUT);
  pinMode(AA2,OUTPUT);
  pinMode(BB1,OUTPUT);
  pinMode(BB2,OUTPUT);
  pinMode(CC1,OUTPUT);
  pinMode(CC2,OUTPUT);

  pinMode (val, INPUT);
  delay(1000);
 
 previousMillis = micros();  
}

void loop() {
  
if(tiempo>1950){ Stop = 0;  
tiempo=1950;
digitalWrite(AA1,LOW);
digitalWrite(AA2,LOW);
digitalWrite(BB1,LOW);
digitalWrite(CC2,LOW);
digitalWrite(BB2,LOW);
digitalWrite(CC1,LOW);
}else{Stop = 1;}


if(Stop==1){
 unsigned long currentMillis = micros();

  
  if(currentMillis - previousMillis >= tiempo){
  
      previousMillis += tiempo;
   
  //Phase1 C-B
  switch(fase){
    case 1:
      digitalWrite(AA1,LOW);
      digitalWrite(AA2,LOW);
      digitalWrite(BB1,LOW);
      digitalWrite(CC2,LOW);
      digitalWrite(BB2,HIGH);
      digitalWrite(CC1,HIGH);
      break;

  //Phase2 A-B
    case 2:
      digitalWrite(AA2,LOW);
      digitalWrite(BB1,LOW);
      digitalWrite(CC1,LOW);
      digitalWrite(CC2,LOW);
      digitalWrite(AA1,HIGH);
      digitalWrite(BB2,HIGH);
      break;

  //Phase3 A-C
    case 3: 
      digitalWrite(AA2,LOW);
      digitalWrite(BB1,LOW);
      digitalWrite(BB2,LOW);
      digitalWrite(CC1,LOW);
      digitalWrite(CC2,HIGH);
      digitalWrite(AA1,HIGH);
    break;   
  
  //Phase4 B-C
  case 4:
      digitalWrite(AA1,LOW);
      digitalWrite(AA2,LOW);
      digitalWrite(BB2,LOW);
      digitalWrite(CC1,LOW);
      digitalWrite(BB1,HIGH);
      digitalWrite(CC2,HIGH);
      break;

  //Phase5 B-A 
  case 5:
      digitalWrite(AA1,LOW);
      digitalWrite(BB2,LOW);
      digitalWrite(CC1,LOW);
      digitalWrite(CC2,LOW);
      digitalWrite(AA2,HIGH);
      digitalWrite(BB1,HIGH);
      break;

  //Phase6 C-A
  case 6:
      digitalWrite(AA1,LOW);
      digitalWrite(BB1,LOW);
      digitalWrite(BB2,LOW);
      digitalWrite(CC2,LOW);
      digitalWrite(CC1,HIGH);
      digitalWrite(AA2,HIGH);
  break;}


  if (fase<6){
    fase=fase+1;}
  else{
    fase=1;
  }
  }
}

  int t = analogRead(val); //From the potentiometer
  tiempo=map(t,0,1024,1,2000); //we obtain the delay speed using the potentiometer

Serial.print(fase);
Serial.print("  ");
Serial.println(tiempo);
}
