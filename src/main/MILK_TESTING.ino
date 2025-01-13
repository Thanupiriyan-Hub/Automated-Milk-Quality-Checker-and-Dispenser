

void Testing() {

  do{
  sensors.requestTemperatures();  // Get the temperature from the sensor and print it
  float temperatureC = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println("°C");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURE OF ");
  lcd.setCursor(0,1);
  lcd.print("THE MILK : ");
  lcd.print(temperatureC);
  delay(2000);

  if(temperatureC<35){
     count++;
  }

  float pHValue = readpH();
  // Display pH and temperature values on serial monitor 
  Serial.print("pH Value: ");
  Serial.println(pHValue);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("PH VALUE OF ");
  lcd.setCursor(0,1);
  lcd.print("THE MILK IS: ");
  lcd.print(pHValue);
  delay(2000);

if(pHValue<9 && pHValue > 5){
     count++;
  }

  int sensorValue = analogRead(gasSensorPin);// Read the gas sensor value
  float voltage = sensorValue * (5.0 / 1023.0);// Convert the sensor value to a voltage
  float gasConcentration = (2.5 - voltage) / 0.2;// Calculate the gas concentration (adjust the parameters for specific gases)
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print("V, Gas Concentration: ");
  Serial.print(gasConcentration);
  Serial.println(" ppm");
  if(sensorValue<20){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("THE MILK CONSIST ");
  lcd.setCursor(0,1);
  lcd.print("OF POISONOUS GAS");
  delay(2000);
  
  }
  else {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NO POISONOUS GAS");
  lcd.setCursor(3,1);
  lcd.print("IN THE MILK");
  delay(2000);
  count++;
  }

  int r, g, b;
  r = process_red_value();
  delay(500);
  g = process_green_value();
  delay(500);
  b = process_blue_value();
  delay(500);
  Serial.print("r = ");
  Serial.print(r);
  Serial.print(" ");
  Serial.print("g = ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print("b = ");
  Serial.print(b);
  
if (r<100 && g<100 && b<100){
  Serial.println("Identified as milk");
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("COLOUR OF MILK IS");
  lcd.setCursor(0,1);
  lcd.print("MATCHED");
  delay(2000);
  count++;
}
else{
  Serial.println("this is not milk");
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("COLOUR OF MILK IS");
  lcd.setCursor(3,1);
  lcd.print("NOT MUCH");
  delay(2000);

 
}
z += 1;


}while(z<1);
testingEnable = false;
lcd.clear();
if(count==4){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("THE MILK IS");
  lcd.setCursor(3,1);
  lcd.print("ACCEPTABLE");
  //Menu();
  BuzzerLoop();
  Open_Door();

 }
  else{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("THE MILK IS ");
  lcd.setCursor(3,1);
  lcd.print("NOT ACCEPT"); 
  }
  delay(3000);
  lcd.clear();
  
}

float readpH() {
  int sensorValue = analogRead(pHPin);
  float voltage = sensorValue * (5.0 / 1024.0);
  float pH = -5.70 * voltage + pHCalibrationValue;
  return pH;
}

void weightCheck(){
  density = weight/volume;
}
int process_red_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, LOW);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
int process_green_value()
{
  digitalWrite(S2_PIN, HIGH);
  digitalWrite(S3_PIN, HIGH);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
int process_blue_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, HIGH);
  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}

