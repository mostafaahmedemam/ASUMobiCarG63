
int red=13;
int yellow=12;
int green=11;


void setup() {
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  

}

void loop() {

digitalWrite(red,HIGH);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);
delay(3000);
digitalWrite(yellow,HIGH);
digitalWrite(red,LOW);
digitalWrite(green,LOW);
delay(3000);
digitalWrite(green,HIGH);
digitalWrite(red,LOW);
digitalWrite(yellow,LOW);
delay(3000);







  
  

}
