int motorA1 = 5; // Pin  2
int motorA2 = 6; // Pin  7 
int motorB1 = 9; // Pin 10 
int motorB2 = 10; // Pin 14 
int velocity = 255; 
int state = '0'; 

void setup() { 
Serial.begin(9600); 
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);
} 

void loop() { 

if(Serial.available()>0){ 
state = Serial.read();
}
if(state=='F'){ // Forward
  Serial.println(state);
analogWrite(motorA1, velocity); 
analogWrite(motorA2, 0); 
analogWrite(motorB1, velocity); 
analogWrite(motorB2, 0); 
}
if(state=='B'){ // Reverse
    Serial.println(state);
analogWrite(motorA1, 0); 
analogWrite(motorA2, velocity);
analogWrite(motorB1, 0); 
analogWrite(motorB2, velocity); 
}
if(state=='L'){ // Right
    Serial.println(state);
analogWrite(motorA1, velocity); 
analogWrite(motorA2, 0); 
analogWrite(motorB1, 0); 
analogWrite(motorB2, velocity); 
}
if(state=='R'){ // Left
    Serial.println(state);
analogWrite(motorA1, 0); 
analogWrite(motorA2, velocity);
analogWrite(motorB1, velocity);
analogWrite(motorB2, 0); 
} 
if(state=='S'){ // Stop
    Serial.println(state);
analogWrite(motorA1, 0); 
analogWrite(motorA2, 0); 
analogWrite(motorB1, 0); 
analogWrite(motorB2, 0); 

}

}
