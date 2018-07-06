int state =0;
int motor_A1=5; //motordriver..2
int motor_A2=6; //motordriver ..7
int motor_b1=9; //motordriver..10
int motor_b2=10; //motordriver..14
int velocity =255;
int RS=7;
int LS=8;
int MS=11;
int LSt;
int MSt;
int RSt;
void setup() {
  // put your setup code here, to run once:
LSt=digitalRead(LS);
RSt=digitalRead(RS);
MSt=digitalRead(MS); 
}

void loop() {
  // put your main code here, to run repeatedly:

              
         if(LSt==LOW&&MSt==HIGH&&RSt==LOW){
       analogWrite(motor_A1,velocity);
        analogWrite(motor_A2,0); // l motor l ymen 2odam
        analogWrite(motor_b1,velocity);
        analogWrite(motor_b2,0); //l motor l shmal 2odam
        }
      if(LSt==HIGH&&MSt==LOW&&RSt==LOW){
          analogWrite(motor_A1,velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,velocity); 
             
        }
       if(LSt==0&&MSt==0&&RSt==1){
       analogWrite(motor_A1,0); 
                analogWrite(motor_A2,velocity);  //ymen wara
                analogWrite(motor_b1,velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
               
        }
        
       if(LSt==1&&MSt==1&&RSt==1){
             analogWrite(motor_A1,velocity);
        analogWrite(motor_A2,0); // l motor l ymen 2odam
        analogWrite(motor_b1,velocity);
        analogWrite(motor_b2,0); //l motor l shmal 2odam
        
        }
        
        if(LSt==0&&MSt==1&&RSt==1){
          analogWrite(motor_A1,0); 
                analogWrite(motor_A2,velocity);  //ymen wara
                analogWrite(motor_b1,velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
                
            
              }
         if(LSt==1&&MSt==1&&RSt==0){
       analogWrite(motor_A1,velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,velocity); 
                 
         }
  if(LSt==0&&MSt==0&&RSt==0){
         analogWrite(motor_A1,0);  
                analogWrite(motor_A2,velocity);  //ymen wara
                analogWrite(motor_b1,velocity);  // shmal 2odam
                analogWrite(motor_b2,0);
                
                delay(1000);
                  analogWrite(motor_A1,velocity);
             analogWrite(motor_A2,0);//ymen 2odam
             analogWrite(motor_b1,0); //shmal wara
             analogWrite(motor_b2,velocity); 
             
                delay(2000);
  }

}
