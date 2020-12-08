const int irpins[6] = {30,31,32,33,34,35};
const int sensorz[6] = {0,0,0,0,0,0};
int i,j = 0;
int d = 1000;
boolean greg=0;
boolean conan=0;
boolean mark =0;
boolean brian=0;
int infra=37;
int irSensors = B000000; 
int motorLSpeed = 255;
int motorRSpeed = 255;
int error = 140; 
int conter=0;
int countery=0;
char blueToothVal; 

///////////////
int input1 = 5; 
int input2 = 4; 

int input3 = 7; 

int input4 = 6;

int counter=0;
int r_speed = 255;
int l_speed = 255;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  for (int i = 0; i <= 5; i++) 
  {pinMode(irpins[i], INPUT);}
  pinMode(input1,OUTPUT);

pinMode(input2,OUTPUT);

pinMode(input3,OUTPUT);

pinMode(input4,OUTPUT);

  pinMode(infra,INPUT);
  conan=0;
  greg=0;
  mark=0;
  counter=0;
  countery=0;
  brian=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  change_speed(100,100);
  scanD();
 
ircheck();
    check();
    delay(10);

}
void check( ) 
{    
     switch (irSensors) {
     

     
     case B100000: // leftmost sensor on the line
     Serial.println("100000");
     left();
     break;
      
     case B010000:
     Serial.println("010000");
     left();
     break;
     
     case B001000: 
     Serial.println("001000");
     left();
     break;
     

     case B000100: 
     Serial.println("000100");
     right();
     break; 
     
     case B000010: 
     Serial.println("000010");
     right();
     break;     

     case B000001: 
    Serial.println("000001");
    right();
     break;
     
     
     
     case B110000:
     Serial.println("110000");
     left();
     break;
      
     case B011000:
     Serial.println("011000");
     
     left();
     break;

     case B001100:
     Serial.println("001100");
     change_speed(130,140);
     forward();
     break;
     
     case B000110: 
     Serial.println("000110");
    
     right();
     break;          

     case B000011:
     Serial.println("000011");
     right();
     break; 

       
       
     case B111000:
     Serial.println("111000"); 
     left(); 
     break;
      
     case B011100:
     Serial.println("011100");
     left();
     break;
     
     case B001110:
     Serial.println("001110");
     right();
     break;
     
     case B000111:
     Serial.println("000111");
     right();
     break;  
     
     
          
     case B111100:
     
     Serial.println("111100");
     ;
     if(greg==0){
     brake();
     conter++;
     delay(1000);
     change_speed(130,130);
    
     if (conter==6){
      greg=1;
      conan=1;
     }
    
     
 
     }
     if(conan==1){
      brake();
      delay(1000);
     conter++;
     left();
     delay(600);
     conan=0;
      
     }
     left();
     break; 
     
     case B011110:
    Serial.println("011110");       
     break;
      
     case B001111:
     
    right();
   
     break;  
     
    
          
     case B111110:
    Serial.println("111110");

     break; 

     case B111111:
     /*if(mark==0){
      brake();
      delay(500);
      counter++;
     if(counter==5){
      right();
      /*delay(950);
      
      counter=0;
      forward();
      delay(900);*/
     /* mark=1;
      brian=1;
      */
      
     }
 
     }
     else { //mark=1;
      brake();
      delay(500);
      countery++;
        if(countery==6){
      left();
    /*  delay(950);
      
      
      forward();
      delay(900);
      countery=0;*/
      mark=0;
     }
     
      
     }
     Serial.println("1111111");
     Serial.println(counter);
     break;

     

     
     
     
     
    
     
    
     
 
     default:
     forward();
     Serial.print("Unhandled case: ");   
     
  }
 Serial.println(conter);
}
int ircheck(){
  int a = digitalRead(infra);
  Serial.print("IR: ");
  Serial.println(a);
 return a;
}
void scanD()
{
  for ( byte count = 0; count < 6;count++ )
{
  bitWrite(irSensors, count, digitalRead( irpins[count] ));
  //bitWrite(referece_bit, count, value) (B0000000)
  
} 
}
void change_speed(int lspeed, int rspeed){
  analogWrite(8,lspeed);
  analogWrite(9,rspeed);
}

void forward() {
  digitalWrite(input1,HIGH); digitalWrite(input2,LOW); digitalWrite(input3,HIGH); digitalWrite(input4,LOW); 
 
  
}
void backward() {
   digitalWrite(input1,LOW); digitalWrite(input2,HIGH); digitalWrite(input3,LOW); digitalWrite(input4,HIGH); 
}
void right(){
  digitalWrite(input1,HIGH); digitalWrite(input2,LOW); digitalWrite(input3,LOW); digitalWrite(input4,LOW); 
}
void left(){
  
digitalWrite(input3,HIGH); digitalWrite(input4,LOW); digitalWrite(input1,LOW); digitalWrite(input2,LOW);
}
void brake(){
  digitalWrite(input1,LOW); digitalWrite(input2,LOW); digitalWrite(input3,LOW); digitalWrite(input4,LOW);
  
}


