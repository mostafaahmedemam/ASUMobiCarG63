const int trigger=12;
const int echo=11;
const int motor=9;
long duration,distance;
void setup(){
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(motor,OUTPUT);
  
}
void loop(){
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  duration=pulseIn(echo,HIGH);
  distance=0.034*duration/2;
  Serial.println(distance);
  if (distance >10){
  analogWrite(motor,255);
  
}
else if(distance<=10){
  analogWrite(motor,0);
  
}
  
  
}

