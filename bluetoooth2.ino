int input1 = 5; // Arduino'nun 3. digital pinine bağlanmıştır.
int input2 = 4; // Arduino'nun 4. digital pinine bağlanmıştır.

int input3 = 7; // Arduino'nun 5. digital pinine bağlanmıştır.
int pot = A0;

int input4 = 6; // Arduino'nun 6. digital pinine bağlanmıştır.
int d =500;

int r_speed = 255;
int l_speed = 255;
char blueToothVal;           //value sent over via bluetooth
char lastValue;  
int b =0;

void setup() { // Serial.begin (9600);

//Motorları sürmek için input pinleri çıkış olarak ayarlandı.

//Motors have been set up to drive the input to the output pins.
Serial.begin(38400); 
pinMode(input1,OUTPUT);

pinMode(input2,OUTPUT);

pinMode(input3,OUTPUT);

pinMode(input4,OUTPUT);

}

void loop() {  
 /* forward();
  delay(2*d);
  brake();
  change_speed(80,80);
  delay(d);
  backward();
  delay(2*d);
  brake();
  delay(d);
  ////////////
*/

int e = analogRead(A0);
  int bt = map(e,0,1024,-20,20);




{
  int e = analogRead(A0);
  int ber = map(e,0,1024,100,200);
  Serial.println(b);
  if(Serial.available())
  {//if there is data being recieved
    blueToothVal=Serial.read();
    Serial.println(blueToothVal);}
    if(blueToothVal=='x'){
      b=255;
      
    }if(blueToothVal=='i'){
      b=120;
      
    }
    if(blueToothVal=='f'){
      forward();
 
  change_speed(120,120+bt);
      digitalWrite(13,HIGH);
    }
    
    else if (blueToothVal=='g') {
      brake();
  
 
  change_speed(120,120);
    }
   else if (blueToothVal=='l'){
    left();
    change_speed(80,80);
   }
   else if (blueToothVal=='r'){
    right();
    change_speed(80,80);
   }
    else if (blueToothVal=='p'){
    backward();
    change_speed(120,120);
   }
}
  

 /* change_speed(50,50);
  delay(d);
  forward();
  delay(d);
  change_speed(255,255);
  backward();
  delay(d);
  change_speed(255,255);
  */

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
void left(){
  digitalWrite(input1,HIGH); digitalWrite(input2,LOW); digitalWrite(input3,LOW); digitalWrite(input4,LOW); 
}
void right(){
  
digitalWrite(input3,HIGH); digitalWrite(input4,LOW); digitalWrite(input1,LOW); digitalWrite(input2,LOW);
}
void brake(){
  digitalWrite(input1,LOW); digitalWrite(input2,LOW); digitalWrite(input3,LOW); digitalWrite(input4,LOW);
  
}

