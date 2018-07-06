int state =0;
int motor_A1=5; //motordriver..2
int motor_A2=6; //motordriver ..7
int motor_b1=9; //motordriver..10
int motor_b2=10; //motordriver..15

int velocity =255;

int echo=4;
  
int trig=3;
float dur,dis;

int RS=2;
int LS=8;
int MS=11;
int LSt=0;
int RSt=0;
int MSt=0;
void Forward(){
      analogWrite(motor_A1,velocity);
        analogWrite(motor_A2,0); // l motor l ymen 2odam
        analogWrite(motor_b1,velocity);
        analogWrite(motor_b2,0); //l motor l shmal 2oda
}
void Backward(){
  analogWrite(motor_A1,0); 
          analogWrite(motor_A2,velocity); //ymen wara
          analogWrite(motor_b1,0); //shmal wara
          analogWrite(motor_b2,velocity);
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
void setup() {
  //b3rf l pins eh outut w eh input 
pinMode(motor_A1,OUTPUT); 
pinMode(motor_A2,OUTPUT);
pinMode(motor_b1,OUTPUT);
pinMode(motor_b2,OUTPUT);

pinMode(LS,INPUT);
pinMode(MS,INPUT);
pinMode(RS,INPUT);

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}

void loop() {
 Serial.println(state);
  // bshof feh data wslt ll bluetooth module wla l2
  if (Serial.available()> 0){
    state= Serial.read(); //b7t l data f variable state
      }
      LSt=digitalRead(LS);
             RSt=digitalRead(RS);
             MSt=digitalRead(MS);  
             
      if (state== 'F'){
        Forward();
      }
       else if (state =='B'){
         Backward();
       }
       else if(state=='R'){
         Right();
       }
       else if(state=='L'){
         Left();
       }
       else if(state=='V')             //Line Follower
       {
                      if(LSt==LOW&&MSt==HIGH&&RSt==LOW){
Forward();

        }
      if(LSt==HIGH&&MSt==LOW&&RSt==LOW){
         Right(); 
          
        }
       if(LSt==0&&MSt==0&&RSt==1){
  Left();
              
        }
        
       if(LSt==1&&MSt==1&&RSt==1){
Forward();
   
        }
        
        if(LSt==0&&MSt==1&&RSt==1){
     Left();
            
              }
         if(LSt==1&&MSt==1&&RSt==0){
     Right();
                  
         }
  if(LSt==0&&MSt==0&&RSt==0){
     Left();
          
     delay(5000);
            Right();
        
                delay(10000);
  }
      
              }
              else if(state=='W')           //Accurate Moving
              {
                // infinity Shape
                Forward();   
                delay(4000);
                Right();
                delay(500);
               Right();
                delay(500);
                Forward();
                delay(4000);
                Left();
                delay(500);
                Left();
                delay(500);
                Forward();
                delay(4000);
                 Left();
                delay(500);
                Left();
                delay(500);
                Forward();
                delay(4000);
                //rectangle Shape
                Stop();
                delay(25000);
                Forward();
                delay(4000);
                Right();
                delay(500);
                Forward();
                delay(5000);
                Right();
                delay(500);
                Forward();
                delay(4000);
                Right();
                delay(500);
                Forward();
                delay(5000);
                //Circle Shape
                Stop();
                delay(25000);
                Right();
                delay(1000);
                Right();
                delay(1000);
                Right();
                delay(1000);
                Right();
                delay(1000);
                
                
                
                
              }
              else{
                Stop();
              }
       }

