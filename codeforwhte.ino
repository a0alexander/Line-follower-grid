// Line follower - Grid based
// Team Project
// Coded by AA

const int irpins[6] = {30,31,32,33,34,35};
const int sensorz[6] = {0,0,0,0,0,0};
int i,j = 0;
int d = 1000;
boolean greg=0;
boolean conan=0;
boolean mark =0;
boolean brian=0;
boolean tim=0;
boolean chris=0;
boolean tick=0;
int counter2=0;
int infra=37;
int irSensors = B000000; 
int motorLSpeed = 255;
int motorRSpeed = 255;
int error = 140; 
int conter=0;
int countery=0;
int dani=0;
char blueToothVal; 
int gh=100;

///////////////
int input1 = 5; 
int input2 = 4; 

int input3 = 7; 

int input4 = 6;

int counter=0;
int r_speed = 255;
int l_speed = 255;
////////////////////
#include <LiquidCrystal.h>
LiquidCrystal lcd(44,45,42,43,40,41);
// Declare lcd as a LiquidCrystal Object
int in = 0;
int jo = 0;
void scrollRightToLeft (int line, char str1[]) {
  in = strlen(str1);
  String label = (String)str1;
  for (jo = 8; jo >= -in; jo--) {
    //lcd.setCursor(0,line);
    /*for (k = 0; k <= i; k++) {
      //lcd.print(" "); // Clear line
    }*/
    lcd.clear();
    if (jo<0)
    {
      lcd.setCursor(0,line);
      label=label.substring(1);
      lcd.print(label);
    }else{
      lcd.setCursor(jo,line);
      lcd.print(str1);
    }

    delay(20);
  }
}

///////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  for (int i = 0; i <= 5; i++) 
  {pinMode(irpins[i], INPUT);}
  pinMode(input1,OUTPUT);

pinMode(input2,OUTPUT);

pinMode(input3,OUTPUT);
digitalWrite(infra,HIGH);
delay(400);
digitalWrite(infra,LOW);
pinMode(input4,OUTPUT);

  pinMode(37,OUTPUT);
  
  conan=0;
  greg=0;
  mark=0;
  counter=0;
  countery=0;
  brian=0;
  counter2=0;
  chris=0;
  tim=0;
  tick=0;
  gh=100;
  dani=200;
    
  lcd.begin(8, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  change_speed(gh,gh);
  scanD();
   lcd.clear();
  lcd.setCursor(0, 1);// 0 th column 1st row
  //convertBinary(irSensors);
 // scrollRightToLeft(0, "helodfe");
  //scrollRightToLeft(1, "GROUP FIVE");

convertBinary(irSensors);
    check();
    delay(10);

}
 void convertBinary(int num){
     int binary [] = {0,0,0,0,0,0};
     int index = 0;
     while(num > 0){
       binary[index++] = num%2;
       num = num/2;
     }
     for(int ig = index-1;ig >= 0;ig--){
       lcd.print(binary[ig]);
       
     }
  }
void check() 
{    
  digitalWrite(37,LOW);
     switch (irSensors) {
     
     case B000000:
     
      digitalWrite(37,HIGH);
 
     
     Serial.println("000000");
     if (tick==1){
     
     
      while(true){
        scanD();
        change_speed(110,110);
        rotateranti();
        delay(10);
        if(irSensors!=B000000){
          tick=0;
           conan=0;
          break;
        }
      }
     
      
      if (conter>30){
        tick=0;
        conan=0;
      }
    
      
      
      
      }
      else {
        while(true){
        scanD();
        change_speed(110,110);
         rotaterclock();
        delay(10);
        if(irSensors!=B000000){
          tick=1;
          conan=1;
          break;
        }
      }
       if (conter>28){
        tick=0;
        conan=0;
      }
       
        
      }
      if (conter>30){
        tick=0;
        conan=0;
      }
     
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
     change_speed(120,125);
     forward();
     break;
     
     case B000110: 
     Serial.println("000110");
    
     right();
     break;          

     case B000011:
     Serial.println("000011");
     brake();
     
     
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
     
     if(conan==1){//&&(conter%5)==0
     /* brake();
      delay(500);
      forward();
      delay(400);*/
      
      left();
      delay(250);
   while(true){
     change_speed(110,110);
        rotaterclock();
        delay(10);
        scanD();
        if(irSensors==B001100){
          
          break;
          conan=0;
        }
   }
      
      
     }
  
     
     if(greg==0){
     brake();
     conter++;
     delay(dani);
     change_speed(120,120);
     forward();
     delay(300);
    
   
    
     
 
     }

     left();
     break; 
     
     case B011110:
    Serial.println("011110");       
     break;
      
     case B001111:
     if (conan==0){
      right();
      delay(200);//&&((conter%5))==0
      while(true){
        scanD();
        change_speed(110,110);
        rotateranti();
        delay(10);
        if(irSensors==B001100){
          conan=1;
          break;
        }
      }
      
     }
     Serial.println("001111");
      if(greg==0){
     brake();
     
     delay(dani);
     change_speed(130,140);
     forward();
     delay(200);
    
  
      }
  
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
      
     brake();
     conter++;
     delay(dani);
  
     change_speed(130,140);
     forward();
     delay(200);
       
     
     
    
      
     
     Serial.println("1111111");
     Serial.println(counter);
     break;

     
 case B110011:
 blinka();
 Serial.println("110011");
 
    break;
    
case B111001:
brake();

blinka();

 Serial.println("111001");
    break;

    
    case B100111:
    blinka();

    
 Serial.println("100111");
    break;
    
     case B100011:

     blinka();
 Serial.println("100011");
    break;
    
     case B110001:
 
     blinka();
 Serial.println("110001");
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
void blinka(){
  digitalWrite(37,HIGH);
  delay(50);
  digitalWrite(37,LOW);
  delay(50);
  digitalWrite(37,HIGH);
  delay(50);
  digitalWrite(37,LOW);
  delay(50);
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
void rotateranti(){
  digitalWrite(input1,HIGH); digitalWrite(input2,LOW);digitalWrite(input3,LOW); digitalWrite(input4,HIGH);
}
void rotaterclock(){
   digitalWrite(input1,LOW); digitalWrite(input2,HIGH);digitalWrite(input3,HIGH); digitalWrite(input4,LOW);
}
