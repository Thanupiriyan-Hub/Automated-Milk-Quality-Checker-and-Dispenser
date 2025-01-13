void Open_Door() {
  delay(1000);
  
  for ( int i = 0 ; i <= 90 ; i++ ) {
       lidServo.write(i);
       delay(50);
       }
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("MILK AHH.....");
  lcd.setCursor(3,1);
  lcd.print("UTHTHUNKADA");
  delay(1000);
  lcd.clear();
  while(DoorEnable){
  lcd.setCursor(1,0);
  lcd.print("PRESS A TO .");
  lcd.setCursor(3,1);
  lcd.print("CLOSE DOOR");
      key = keypad.getKey();
      if(key=='A'){
        DoorCloseEnable = true;
        
      }
        if(DoorCloseEnable){
          lcd.clear();
        for ( int i = 90 ; i >= 0 ; i-- ) {
       lidServo.write(i);
       delay(50);
       }
        
       DoorCloseEnable = false;
       DoorEnable = false;

        }
  }
  Menu();

}

void BuzzerLoop(){
  digitalWrite(Buzzer,HIGH);
  delay(50);
  digitalWrite(Buzzer,LOW);
  delay(50);
  digitalWrite(Buzzer,HIGH);
  delay(50);
  digitalWrite(Buzzer,LOW);

}