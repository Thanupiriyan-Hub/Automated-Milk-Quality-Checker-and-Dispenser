void Menu(){ 

 do{
  InputNumber();
  lcd.setCursor(0,0);
  lcd.print("ENTER THE AMOUNT");
  lcd.setCursor(0,1);
  lcd.print("OF THE MILK : ");
  lcd.print(value);
  
  Half_L_Count= value*2;
  if(value > 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("FILLING PROCESS");
    Half_Tank();
  }
  }while(HalF_Enable);
 delay(20);

}

void Half_Tank(){
  for(int i =0; i< Half_L_Count; i++){
    lcd.setCursor(0,1);
    lcd.print("FILLING ");
    int sensorValue = digitalRead(Level_Sensor);
     
      digitalWrite(Solonid_Half_IN,HIGH);
 if(sensorValue == 1){
          digitalWrite(Solonid_Half_IN,LOW);
          delay(500);
          digitalWrite(Solonid_Half_OUT,HIGH);
          delay(2000);  //TIME FOR MILK OUTFLOW FROM 1/2 CONTAINER
          digitalWrite(Solonid_Half_OUT, LOW);
      }
      delay(1000);
  }
 HalF_Enable=false;
 lcd.clear();
Costomer();
}

void  Costomer(){
   while(CostomerEnable){
      key = keypad.getKey(); 
      int CupsensorValue = digitalRead(Cup_Level_Sensor);

      if(CupsensorValue ==1){
           delay(1000);
           lcd.setCursor(0,1);
           lcd.print("GET MILK");
           digitalWrite(Solonid_Customer,HIGH);
      }
      else{
          lcd.setCursor(0,1);
          lcd.print("PLCE THE CUP");
      }

    if(key=='#'){
     CostomerEnable = false;
 }   
   }
  digitalWrite(Solonid_Customer,LOW);
  delay(200);
}