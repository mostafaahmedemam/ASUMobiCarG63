char state=0; ;
int motor_A1=5; //motordriver..2
int motor_A2=6; //motordriver ..7
int motor_b1=9; //motordriver..10
int motor_b2=10; //motordriver..14
int velocity =255;
int echo=4;
int trig=3;
float dur,dis;
const int pinL=7;
const int pinR=8;
const int pinC=11;
int LS=0;
int RS=0;
int MS=0;
int a;
void Forward(){
  analogWrite(motor_A1,0); 
          analogWrite(motor_A2,velocity); //ymen wara
          analogWrite(motor_b1,0); //shmal wara
          analogWrite(motor_b2,velocity*0.45);
}

void Backward(){
   analogWrite(motor_A1,velocity);
        analogWrite(motor_A2,0); // l motor l ymen 2odam
        analogWrite(motor_b1,velocity*0.45);
        analogWrite(motor_b2,0); //l motor l shmal 2odam
  
}

void Right(){
  analogWrite(motor_A1,0); 
                analogWrite(motor_A2,velocity);  //ymen wara
                analogWrite(motor_b1,velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
}

void Left(){
  analogWrite(motor_A1,velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,velocity);
}
void Stop(){
  
                analogWrite(motor_A1,0); 
                analogWrite(motor_A2,0);  //ymen yo2f
                analogWrite(motor_b1,0);  // shmal yo2f
                analogWrite(motor_b2,0);
}
void Circle(){
  analogWrite(motor_A1,0); 
          analogWrite(motor_A2,velocity); //ymen wara
          analogWrite(motor_b1,0); //shmal wara
          analogWrite(motor_b2,velocity*0.1);
}
void Circle_left(){
  analogWrite(motor_A1,0); 
          analogWrite(motor_A2,velocity*0.1); //ymen wara
          analogWrite(motor_b1,0); //shmal wara
          analogWrite(motor_b2,velocity); 
}

void setup() {
  //b3rf l pins eh outut w eh input 
pinMode(motor_A1,OUTPUT); 
pinMode(motor_A2,OUTPUT);
pinMode(motor_b1,OUTPUT);
pinMode(motor_b2,OUTPUT);
LS=digitalRead(pinL);
RS=digitalRead(pinR);
MS=digitalRead(pinC);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}




void loop() {
 digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur=pulseIn(echo,HIGH);
  dis=dur*.043/2;
  Serial.print("distance");
  Serial.println(dis);
  // bshof feh data wslt ll bluetooth module wla l2
  if (Serial.available()> 0){
    state= Serial.read(); //b7t l data f variable state
      }
      
      if (state== 'B'){
       // for forward
        Backward();
      }
        
        else if (state =='F'){
          //backward
         Forward();
           }
          
          else if (state == 'L'){
            //right
            Left();
            }
            
            else if (state =='R'){
              //left
               Right();
              }
          
              
             else if(dis<=40)
              {
                 Stop();
                              }
                              
              else if(state=='V'){                
              
  if(LS==LOW &&MS==HIGH && RS==LOW){
   Forward();
  }
 else if(LS==HIGH && MS==LOW && RS==LOW){
Right();
  }
 else if(LS==LOW &&MS==LOW && RS==HIGH){
Left(); 
  }
 else if(LS==LOW && MS==LOW && RS==LOW){
Right();
             delay(2000);
  Right();
 delay(4000);            
             
 }
              }
           
           else if(state=='W')                     //accurate move
           {
             // infinity Shape
             Circle();
             delay(3000);
             Right();
             delay(500);
             Forward();
             delay(2000);
             Circle_left();
             delay(500);
             Left();
             delay(500);
             Forward();
             delay(2000);
             
             
           /*  Forward();
             delay (2000);
             Right();
             delay(500);
             Right();
             delay(500);
             Forward();
             delay(2000);
             Left();
             delay(500);
             Left();
             delay(500);
             Forward();
             delay(2000);
             Left();
             delay(500);
             Left();
             delay(500);
             Forward();
             delay(2000);  */
             // Rectangle Shape
             Stop();
             delay(5000);
             Forward();
             delay(2000);
             Right();
             delay(500);
             Forward();
             delay(1500);
             Right();
             delay(500);
             Forward();
             delay(2000);
             Right();
             delay(500);
             Forward();
             delay(1500);    
             // Circle Shape
             Stop();
             delay(5000);
            
              Circle();
              delay(3000);
              Stop();
              
             
             
           }  
          
      else if(state=='S'){
  Stop();
}
 else Stop;
      switch(state)
     {
  case'D':
  
    int value=Serial.parseInt();
      int t=value;
      Forward();
       delay(t);
  break;
  case'H':
  
    int value=Serial.parseInt();char state=0; ;
int motor_A1=5; //motordriver..2
int motor_A2=6; //motordriver ..7
int motor_b1=9; //motordriver..10
int motor_b2=10; //motordriver..14
int velocity =255;
int echo=4;
int trig=3;
float dur,dis;
const int pinL=13;
const int pinR=2;
const int pinC=12;
int LS;
int RS;
int MS;
int a,t,value;
void Forward(){
  analogWrite(motor_A1,0); 
          analogWrite(motor_A2,velocity); //ymen wara
          analogWrite(motor_b1,0); //shmal wara
          analogWrite(motor_b2,velocity*.75);
}

void Backward(){
   analogWrite(motor_A1,velocity);
        analogWrite(motor_A2,0); // l motor l ymen 2odam
        analogWrite(motor_b1,velocity*.75);
        analogWrite(motor_b2,0); //l motor l shmal 2odam
  
}

void Right(){
  analogWrite(motor_A1,0); 
                analogWrite(motor_A2,velocity);  //ymen wara
                analogWrite(motor_b1,velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
}

void Left(){
  analogWrite(motor_A1,velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,velocity);
}





//line follower directions
void Forward2(){
  analogWrite(motor_A1,0); 
          analogWrite(motor_A2,.2*velocity); //ymen wara
          analogWrite(motor_b1,0); //shmal wara
          analogWrite(motor_b2,.2*velocity*.75);
}

void Backward2(){
   analogWrite(motor_A1,.2*velocity);
        analogWrite(motor_A2,0); // l motor l ymen 2odam
        analogWrite(motor_b1,.2*velocity*.75);
        analogWrite(motor_b2,0); //l motor l shmal 2odam
  
}

void Right2(){
  analogWrite(motor_A1,0); 
                analogWrite(motor_A2,.2*velocity);  //ymen wara
                analogWrite(motor_b1,.2*velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
}

void Left2(){
  analogWrite(motor_A1,.2*velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,.2*velocity);
}



void Stop(){
  
                analogWrite(motor_A1,0); 
                analogWrite(motor_A2,0);  //ymen yo2f
                analogWrite(motor_b1,0);  // shmal yo2f
                analogWrite(motor_b2,0);
}
void Circle(){
  analogWrite(motor_A1,0); 
          analogWrite(motor_A2,velocity); //ymen wara
          analogWrite(motor_b1,0); //shmal wara
          analogWrite(motor_b2,velocity*0.4);
}
void Circle_left(){
  analogWrite(motor_A1,0); 
          analogWrite(motor_A2,velocity*.5); //ymen wara
          analogWrite(motor_b1,0); //shmal wara
          analogWrite(motor_b2,velocity*.75); 
}

void setup() {
  //b3rf l pins eh outut w eh input 
pinMode(motor_A1,OUTPUT); 
pinMode(motor_A2,OUTPUT);
pinMode(motor_b1,OUTPUT);
pinMode(motor_b2,OUTPUT);
LS=digitalRead(pinL);
RS=digitalRead(pinR);
MS=digitalRead(pinC);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}




void loop() {
 digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dur=pulseIn(echo,HIGH);
  dis=dur*.043/2;
  
  Serial.print("distance");
  Serial.println(dis);
  // bshof feh data wslt ll bluetooth module wla l2
  if (Serial.available()> 0){
    state= Serial.read(); //b7t l data f variable state
      }
       if(dis<=60)
              {
                 Stop();
                 delay(1000);
                 Backward();
                 delay(1000);
                 Stop();
                             }
        else{
            
      if (state== 'B'){
       // for forward
        Backward();
      }
        
        else if (state =='F'){
          //backward
         Forward();
           }
          
          else if (state == 'L'){
            //right
            Left();
            }
            
            else if (state =='R'){
              //left
               Right();
              }
          
              
                              
              else if(state=='V'){                
                Serial.print("ls=");
  Serial.println(LS);
  Serial.print("ms=");
  Serial.println(MS);
  Serial.print("rs=");
  Serial.println(RS);
              
  if((LS==LOW &&MS==HIGH && RS==LOW) || (LS==HIGH && MS==HIGH && RS==HIGH)){
   Forward2();
  }
 else if((LS==HIGH && MS==LOW && RS==LOW) ||( MS==HIGH && LS==HIGH && RS==LOW)){
Left2();
  }
 else if((LS==LOW &&MS==LOW && RS==HIGH)|| (RS==HIGH && MS==HIGH && LS==LOW)){
Right2(); 
  }
 else if(LS==LOW && MS==LOW && RS==LOW){
Right2();
             delay(1000);
  Left2();
 delay(2000);            
             
 }
 else Stop();
              }

      int t=value;
      Backward();
       delay(t);
  break;

}

}

            
  
 }

