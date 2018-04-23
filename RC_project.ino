int state =0;
int motor_A1=5; //motordriver..2
int motor_A2=6; //motordriver ..7
int motor_b1=9; //motordriver..10
int motor_b2=10; //motordriver..15
int motor_c1=3;//....2
int motor_c2=7;//....7
int motor_d1=12;//...1
int motor_d2=13;//...15
int velocity =255;

/*int echo=
 * ;
int trig=3
float dur,dis;
*/
int RS=2;
int LS=8;
int MS=11;
int LSt=0;
int RSt=0;
int MSt=0;

void setup() {
  //b3rf l pins eh outut w eh input 
pinMode(motor_A1,OUTPUT); 
pinMode(motor_A2,OUTPUT);
pinMode(motor_b1,OUTPUT);
pinMode(motor_b2,OUTPUT);
pinMode(motor_c1,OUTPUT); 
pinMode(motor_c2,OUTPUT);
pinMode(motor_d1,OUTPUT);
pinMode(motor_d2,OUTPUT);
pinMode(LS,INPUT);
pinMode(MS,INPUT);
pinMode(RS,INPUT);
/*
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);*/
Serial.begin(9600);
}




void loop() {
 Serial.println(state);
  // bshof feh data wslt ll bluetooth module wla l2
  if (Serial.available()> 0){
    state= Serial.read(); //b7t l data f variable state
      }
      
      if (state== 'F'){
       // for forward
        analogWrite(motor_A1,velocity);
        analogWrite(motor_A2,0); // l motor l ymen 2odam
        analogWrite(motor_b1,velocity);
        analogWrite(motor_b2,0); //l motor l shmal 2odam
        analogWrite(motor_c1,velocity);
        analogWrite(motor_c2,0); // l motor l ymen 2odam
        analogWrite(motor_d1,velocity);
        analogWrite(motor_d2,0); //l motor l shmal 2odam
      }
        
        else if (state =='B'){
          //backward
          analogWrite(motor_A1,0); 
          analogWrite(motor_A2,velocity); //ymen wara
          analogWrite(motor_b1,0); //shmal wara
          analogWrite(motor_b2,velocity);
          analogWrite(motor_c1,0); 
          analogWrite(motor_c2,velocity); //ymen wara
          analogWrite(motor_d1,0); //shmal wara
          analogWrite(motor_d2,velocity);
           }
          
          else if (state == 'L'){
            //right
             analogWrite(motor_A1,velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,velocity); 
             analogWrite(motor_c1,0);
             analogWrite(motor_c2,velocity);//ymen 2odam
             analogWrite(motor_d1,velocity); //shmal wara
             analogWrite(motor_d2,0);
            }
            
            else if (state =='R'){
              //left11111
                analogWrite(motor_A1,0); 
                analogWrite(motor_A2,velocity);  //ymen wara
                analogWrite(motor_b1,velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
                analogWrite(motor_c1,velocity); 
                analogWrite(motor_c2,0);  //ymen wara
                analogWrite(motor_d1,0);  // shmal 2odam
                analogWrite(motor_d2,velocity);
              }
                else {
                analogWrite(motor_A1,0); 
                analogWrite(motor_A2,0);  //ymen yo2f
                analogWrite(motor_b1,0);  // shmal yo2f
                analogWrite(motor_b2,0);
                analogWrite(motor_c1,0); 
                analogWrite(motor_c2,0);  //ymen yo2f
                analogWrite(motor_d1,0);  // shmal yo2f
                analogWrite(motor_d2,0);
              }
       
             LSt=digitalRead(LS);
             RSt=digitalRead(RS);
             MSt=digitalRead(MS);  
         if(LSt==LOW&&MSt==HIGH&&RSt==LOW){
       analogWrite(motor_A1,velocity);
        analogWrite(motor_A2,0); // l motor l ymen 2odam
        analogWrite(motor_b1,velocity);
        analogWrite(motor_b2,0); //l motor l shmal 2odam
        analogWrite(motor_c1,velocity);
        analogWrite(motor_c2,0); // l motor l ymen 2odam
        analogWrite(motor_d1,velocity);
        analogWrite(motor_d2,0); //l motor l shmal 2odam
        }
      if(LSt==HIGH&&MSt==LOW&&RSt==LOW){
          analogWrite(motor_A1,velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,velocity); 
             analogWrite(motor_c1,0);
             analogWrite(motor_c2,velocity);//ymen 2odam
             analogWrite(motor_d1,velocity); //shmal wara
             analogWrite(motor_d2,0);
        }
       if(LSt==0&&MSt==0&&RSt==1){
       analogWrite(motor_A1,0); 
                analogWrite(motor_A2,velocity);  //ymen wara
                analogWrite(motor_b1,velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
                analogWrite(motor_c1,velocity); 
                analogWrite(motor_c2,0);  //ymen wara
                analogWrite(motor_d1,0);  // shmal 2odam
                analogWrite(motor_d2,velocity);
        }
        
       if(LSt==1&&MSt==1&&RSt==1){
             analogWrite(motor_A1,velocity);
        analogWrite(motor_A2,0); // l motor l ymen 2odam
        analogWrite(motor_b1,velocity);
        analogWrite(motor_b2,0); //l motor l shmal 2odam
        analogWrite(motor_c1,velocity);
        analogWrite(motor_c2,0); // l motor l ymen 2odam
        analogWrite(motor_d1,velocity);
        analogWrite(motor_d2,0); //l motor l shmal 2odam
        }
        
        if(LSt==0&&MSt==1&&RSt==1){
          analogWrite(motor_A1,0); 
                analogWrite(motor_A2,velocity);  //ymen wara
                analogWrite(motor_b1,velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
                analogWrite(motor_c1,0); 
                analogWrite(motor_c2,velocity);  //ymen wara
                analogWrite(motor_d1,0);  // shmal 2odam
                analogWrite(motor_d2,velocity);
            
              }
         if(LSt==1&&MSt==1&&RSt==0){
       analogWrite(motor_A1,velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,velocity); 
             analogWrite(motor_c1,0);
             analogWrite(motor_c2,velocity);//ymen 2odam
             analogWrite(motor_d1,velocity); //shmal wara
             analogWrite(motor_d2,0);       
         }
  if(LSt==0&&MSt==0&&RSt==0){
         analogWrite(motor_A1,0);  
                analogWrite(motor_A2,velocity);  //ymen wara
                analogWrite(motor_b1,velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
                analogWrite(motor_c1,velocity); 
                analogWrite(motor_c2,0);  //ymen wara
                analogWrite(motor_d1,0);  // shmal 2odam
                analogWrite(motor_d2,velocity);
                delay(5000);
                  analogWrite(motor_A1,velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,velocity); 
             analogWrite(motor_c1,0);
             analogWrite(motor_c2,velocity);//ymen 2odam
             analogWrite(motor_d1,velocity); //shmal wara
             analogWrite(motor_d2,0);
                delay(10000);
  }
        
      
}
