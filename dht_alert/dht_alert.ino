#include <dht.h>
#define dht_pin 5   //訊號從pin 5 進來
#define led_pin 6   //LED 輸出的電位
dht DHT;

int Alert_Value = 60;
int count = 20;

void setup(){
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  delay(1000);
}

void loop(){
  if(count == 0){
    DHT.read11(dht_pin);    
    print_HT();
    count = 20;
  }
  
  if(DHT.humidity > 40 && count % 2 ==0){
    digitalWrite(led_pin,HIGH); 
  }else{
    digitalWrite(led_pin,LOW);
  }
  
  count--;
  delay(50);
}


void print_HT(){
  Serial.print("Humidity = ");   
  Serial.print(DHT.humidity);   
  Serial.print("% ");   
  Serial.print("temperature = ");   
  Serial.print(DHT.temperature);   
  Serial.println("C ");
}



