/*smartbox1.0 is a device which can be easily implemented in a house and can be used as a home automation device
 * it has two  modes of working it can control any home appliance which is plugged in the box by bluetooth 
 and by the click of a button the ode changes and it turn into a smart electricity  saver lamp as we many times after doing our work forgot to switch of the lights
 so i have integrate the ultrasonic sensor in the smart n=box in such a way that if u are sitting in front of the bow and u have plugged in your lamp in the box it only turns on
 when you are in front of it otherwise it will be turned off which inturn save electricity 
 the main purpose of the project was to use it in home automaion and making human life easier*/
char bata = 0;   //Variable for storing received data
int relaypin = 3;
int relaypin2 =4;
int relaypin3 =5;
int trigPin = 6;    
int echoPin = 7;    
long duration, cm;
int sensorPin = A0; 
int sensorValue = 8;
int modepin=9;



 
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(relaypin,OUTPUT);
  pinMode(relaypin2,OUTPUT);
  pinMode(relaypin3,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(sensorPin,INPUT);
   pinMode(modepin,INPUT);
   




}
void loop()
{
if(digitalRead(modepin)==HIGH)
{

    if(Serial.available() > 0)  // Send data only when you receive data:
     {  
      bata = Serial.read();      //Read the incoming data and store it into variable data
       Serial.print(data);        //Print Value inside data in Serial monitor
      Serial.print("\n");        //New line 
    if(bata == '1')    //Checks whether value of data is equal to 1 
      {
        digitalWrite(3, HIGH);  //If value is 1 then LED turns ON
        digitalWrite(relaypin,HIGH);
      }
    else if(bata == '5')       //Checks whether value of data is equal to 0
      {
        digitalWrite(3, LOW);   //If value is 0 then LED turns OFF
        digitalWrite(relaypin,LOW);
      }                            
    else if(bata == '2')       //Checks whether value of data is equal to 0
      {
      digitalWrite(relaypin2, HIGH);   //If value is 0 then LED turns OFF
      }            
    else if(bata == '6')       //Checks whether value of data is equal to 0
      {
       digitalWrite(relaypin2, LOW);   //If value is 0 then LED turns OFF
      }                     
    else if(bata == '3')       //Checks whether value of data is equal to 0
      {
        digitalWrite(relaypin3, HIGH);   //If value is 0 then LED turns OFF
      }                           
    else if(bata == '7')       //Checks whether value of data is equal to 0
      {
      digitalWrite(relaypin3, LOW);   //If value is 0 then LED turns OFF
      }
     }
 }  
 if(digitalRead(modepin)==LOW)
 {
          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);            //ultrasonic
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
       
          duration = pulseIn(echoPin, HIGH);
    
           cm = (duration/2) / 29.1;    //print
           Serial.print(cm);
           Serial.print("cm");
           Serial.println();
     
 if(cm<50)
      {
        digitalWrite(relaypin,HIGH);   
       
       }
    else
      {
       digitalWrite(relaypin,LOW);
       
      }
  
 }

}
