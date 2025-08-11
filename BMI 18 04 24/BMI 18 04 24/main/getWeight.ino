float getWeight(){

  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  lcd.setCursor(0,0); 
  //lcd.print("Please wait");
  delay(1000);
  //lcd.setCursor(0,0); 
  //lcd.print (" Reading....");
  Serial.print("Reading: ");
  weight = scale.get_units(5); 
 // a = weight - .5  ;
  //Serial.print(scale.get_units(), 2);
 // Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print("Kilogram:");
   //lcd.print (" Kilogram:");
 // lcd.setCursor(0,1); 
  Serial.print( weight); 
 // lcd.print (weight);
  Serial.print(" Kg");
 // lcd.print (" Kg");
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println(); 
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 200;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 200;
  }

  return weight;
}
