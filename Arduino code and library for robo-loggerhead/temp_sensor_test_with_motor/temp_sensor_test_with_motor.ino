#include <DallasTemperature.h>

#include <OneWire.h>

//int greenLedPin = 2;
//int yellowLedPin = 3;
//int redLedPin = 4;

int temp_sensor = 3;
float temperature = 0;
int lowerLimit = 15;
int higherLimit = 35;
OneWire oneWirePin(temp_sensor);
DallasTemperature sensors(&oneWirePin);
// for motor//
const int AI2 = 8;     //motor A
      const int AI1 = 9;
      const int PWM_A = 4;
      
      const int BI2 = 10;    // motor B
      const int BI1 = 11;
      const int PWM_B = 5;
      //end//


void setup(void){
  Serial.begin(9600);
  
  //Setup the LEDS to act as outputs
//  pinMode(redLedPin,OUTPUT);
  //pinMode(greenLedPin,OUTPUT);
 // pinMode(yellowLedPin,OUTPUT);
  
  sensors.begin();
  //for motor//
        pinMode(AI2, OUTPUT); 
      pinMode(AI1, OUTPUT); 
      pinMode(PWM_A, OUTPUT);
      pinMode(BI2, OUTPUT);
      pinMode(BI1, OUTPUT);
      pinMode(PWM_B, OUTPUT);
      //end//
}
void loop(){
  Serial.print("Requesting Temperatures from sensors: ");
  sensors.requestTemperatures(); 
  Serial.println("DONE");
  delay(1000);
  
  temperature = sensors.getTempCByIndex(0);
//  digitalWrite(redLedPin, LOW);
//  digitalWrite(greenLedPin, LOW);
//  digitalWrite(yellowLedPin, LOW);
  
  Serial.print("Temperature is ");
  Serial.print(temperature);
  //Setup the LEDS to act as outputs
if(temperature <= lowerLimit){ 
    Serial.println(", motor is Activated"); 
          digitalWrite(AI2, HIGH);
       digitalWrite(AI1, LOW);
       analogWrite(PWM_A, 255);   //sets speed, motor A
       digitalWrite(BI2, HIGH);
       digitalWrite(BI1, LOW);
       analogWrite(PWM_B, 255);  //sets speed, motor B
      
       //wait 1 second
       delay(1000);
      
   // digitalWrite(yellowLedPin, HIGH); 
   } 
else if(temperature > lowerLimit && temperature < higherLimit){ 
    Serial.println(", Green LED is Activated"); 
    //digitalWrite(greenLedPin, HIGH);
          
       digitalWrite(AI2, LOW);
       digitalWrite(AI1, LOW);
       analogWrite(PWM_A, 0);
       digitalWrite(BI2, LOW);
       digitalWrite(BI1, LOW);
       analogWrite(PWM_B, 0);
} 
else if(temperature >= higherLimit){
    Serial.println(", Red LED is Activated");
   // digitalWrite(redLedPin, HIGH);
    digitalWrite(AI2, HIGH);
       digitalWrite(AI1, LOW);
       analogWrite(PWM_A, 255);   //sets speed, motor A
       digitalWrite(BI2, HIGH);
       digitalWrite(BI1, LOW);
       analogWrite(PWM_B, 255);  //sets speed, motor B
      
       //wait 1 second
       delay(1000);
}
delay(500);
}
