int Lswitch = 2;
int Lswitch2 = 3;
int led = 12;
int carrera = 0;
int carrera2 = 0;
const int pinENA = 6;
const int pinIN1 = 7;
const int pinIN2 = 8;
const int speed = 200;

void setup()
{
   Serial.begin(9600);
   pinMode(Lswitch, INPUT);
   pinMode(Lswitch2, INPUT);
   pinMode(led, OUTPUT);
   pinMode(pinIN1, OUTPUT);
   pinMode(pinIN2, OUTPUT);
   pinMode(pinENA, OUTPUT);
}

void adelante ()
{
   digitalWrite(pinIN1, HIGH);
   digitalWrite(pinIN2, LOW);
   analogWrite(pinENA, speed);
}

void atras ()
{
   digitalWrite(pinIN1, LOW);
   digitalWrite(pinIN2, HIGH);
   analogWrite(pinENA, speed);  
}

void loop()
{
  carrera = digitalRead(Lswitch);
  carrera2 = digitalRead(Lswitch2);
  Serial.print(carrera);
  Serial.print("      ");
  Serial.println(carrera2);
delay(500);
 
  if ((carrera==0)&&(carrera2==1))
  {
   adelante();
   digitalWrite(led,HIGH);
  }
   
if ((carrera2==0)&&(carrera==1))
{
  atras();
  digitalWrite(led,LOW);
}

  digitalWrite(Lswitch,HIGH);
  digitalWrite(Lswitch,LOW);
    digitalWrite(Lswitch2,HIGH);
  digitalWrite(Lswitch2,LOW);
}
