int soil_sensor=A0;
int value;
int pump=10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(soil_sensor,INPUT);
  pinMode(pump,OUTPUT);
}

void loop() {
  
  Serial.print("MOISTURE LEVEL:  ");
  value=analogRead(soil_sensor);
  Serial.println(value);
  if (value>800){
    digitalWrite(pump,HIGH);
  }
  else{
    digitalWrite(pump,LOW);
  }
  delay(3600000);
}
