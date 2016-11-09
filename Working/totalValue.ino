const int soilPin = A2; 
const int tempPin = A3;
const int lightPin = A4;

int soilValue = 0;
int tempValue = 0;
int lightValue = 0;
String totalValue;


void setup()
{
  totalValue = String();
  Serial.begin(9600);  
}
void loop()                    
{
 float tempValue = getTemp();  
 soilValue = analogRead(soilPin);  
 lightValue = analogRead(lightPin);
 totalValue = soilValue + "," + String(tempValue) + "," + lightValue;
 Serial.println(totalValue);                     
 delay(6000);                                                                        
}

float getTemp()
{
  int reading = analogRead(tempPin);
  
  float voltage = (reading * 5.0) / 1024;
  return (voltage - 0.5) * 100;
}