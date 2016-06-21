#include <dht.h>
#define dht_pin 5   //訊號從pin 5 進來
dht DHT;

int Alert_Value = 60;

void setup(){
  Serial.begin(9600);
  delay(1000);
}

void loop(){
  DHT.read11(dht_pin);    
  print_HT();
  if(DHT.humidity > Alert_Value){
    Serial.println("Warning! It's going to rain\n");
  }
  delay(1000);
}


void print_HT(){
  Serial.print("Humidity = ");   
  Serial.print(DHT.humidity);   
  Serial.print("% ");   
  Serial.print("temperature = ");   
  Serial.print(DHT.temperature);   
  Serial.println("C ");
}



