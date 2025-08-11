// Function to print result
void printResult(int db[][4], int height, float weight, int gender){
  // Code Begin
// Printing user height
  lcd.setCursor(0, 0);  
  lcd.print("Your height is:" );
  lcd.setCursor(0,1);
  lcd.print(height);
  lcd.print("cms");
  delay(8000);
  Serial.print("Your height is :");
  Serial.print(height);
  Serial.println(" cms");
// Printing user weight
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Your weight is :");
  lcd.setCursor(0 ,1);
  lcd.print(weight);
  lcd.println("kgs");
  delay(8000);
  Serial.print("Your weight is :");
  Serial.print(weight);
  Serial.println(" kgs");
  lcd.clear();  
  
   
  if(height < 137){
      lcd.setCursor(0,0);
      lcd.print ("OOPS !!! height lesser than 137 cm can't be processed");
    Serial.println("OOPS !!! height lesser than 137 cm can't be processed");
    
  }
  else if(height > 195){
    lcd.setCursor(0,0);
    lcd.print ("OOPS !!! height greater than 195 cm can't be processed");
    Serial.println("OOPS !!! height greater than 195 cm can't be processed");
  }
  else{ // Entry point for height within range
    float lower_bound, upper_bound; // lower_bound & upper_bound nothing but lowest & highest allowable weight for a perticular height
    if(digitalRead (gender) == HIGH){ // Entry point for females
      lower_bound = (float)db[height-H][0]/10;
      upper_bound = (float)db[height-H][1]/10;
      if(weight >= lower_bound && weight <= upper_bound){ // when weight is in control
        lcd.setCursor(0,0);
        lcd.print("optimum weight");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("weight should be");
        lcd.setCursor(0,1);
        lcd.print(lower_bound );
        lcd.print ("kgs to");
        //lcd.setCursor(0,1);
        lcd.print(upper_bound);
        lcd.print("kgs"); 
        delay(8000); 
        lcd.clear();     
        Serial.print(" kgs to ");
        Serial.println("Yehhh!!! Your weight is under control");
        Serial.print("Your exact weight should be in range between ");
        Serial.print(lower_bound);
        Serial.print(" kgs to ");
        Serial.print(upper_bound);
        Serial.println("kgs");
      }
      else if(weight < lower_bound){ // under weight
        lcd.setCursor(0,0);
        lcd.print("under weight");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("weight should be");
        lcd.setCursor(0,1);
        lcd.print(lower_bound );
        lcd.print ("kgs to");
        //lcd.setCursor(0,1);
        lcd.print(upper_bound);
        lcd.print("kgs"); 
        delay(8000); 
        lcd.clear();     
        Serial.println("OOPS!!! Your are under weight");
        Serial.print("Your exact weight should be in range between ");
        Serial.print(lower_bound);
        Serial.print(" kgs to ");
        Serial.print(upper_bound);
        Serial.println(" kgs");
      }
      else{ //  over weight
        lcd.setCursor(0,0);
        lcd.print("over weight");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("weight should be");
        lcd.setCursor(0,1);
        lcd.print(lower_bound );
        lcd.print ("kgs to");
        //lcd.setCursor(0,1);
        lcd.print(upper_bound);
        lcd.print("kgs"); 
        delay(8000); 
        //lcd.clear();     
        Serial.println("OOPS!!! Your are over weight");
        Serial.print("Your exact weight should be in range between ");
        Serial.print(lower_bound);
        Serial.print(" kgs to ");
        Serial.print(upper_bound);
        Serial.println(" kgs");
      }

      // Calculating BMI

      BMI = ((weight/height)/height)*10000;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Your BMI is :");
      lcd.print(BMI);
      delay(6000);
      Serial.print("Your Accurate BMI is :");
      Serial.println(BMI);
      

      
    }
    else 
    // Entry point for males
    { 
      lower_bound = (float)db[height-H][2]/10;
      upper_bound = (float)db[height-H][3]/10;
      if(weight >= lower_bound && weight <= upper_bound){  // when weight is in control
        lcd.setCursor(0,0);
        lcd.print("optimum weight");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("weight should be");
        lcd.setCursor(0,1);
        lcd.print(lower_bound );
        lcd.print ("kgs to");
        //lcd.setCursor(0,1);
        lcd.print(upper_bound);
        lcd.print("kgs"); 
        delay(8000); 
        lcd.clear();     
        Serial.println("Yehhh!!! Your weight is under control");
        Serial.print("Your exact weight should be in range between ");
        Serial.print(lower_bound);
        Serial.print(" kgs to ");
        Serial.print(upper_bound);
        Serial.println(" kgs");
      }
      else if(weight < lower_bound){ // under weight
        lcd.setCursor(0,0);
        lcd.print("under weight");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("weight should be");
        lcd.setCursor(0,1);
        lcd.print(lower_bound );
        lcd.print ("kgs to");
        //lcd.setCursor(0,1);
        lcd.print(upper_bound);
        lcd.print("kgs"); 
        delay(8000); 
        lcd.clear();     
        Serial.println("OOPS!!! Your are under weight");
        Serial.print("Your exact weight should be in range between ");
        Serial.print(lower_bound);
        Serial.print(" kg to ");
        Serial.print(upper_bound);
        Serial.println(" kg");
      }
      else{ // over weight
        lcd.setCursor(0,0);
        lcd.print("over weight");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("weight should be");
        lcd.setCursor(0,1);
        lcd.print(lower_bound );
        lcd.print ("kgs to");
        //lcd.setCursor(0,1);
        lcd.print(upper_bound);
        lcd.print("kgs"); 
        delay(8000); 
       // lcd.clear();     
        Serial.println("OOPS!!! Your are over weight");
        Serial.print("Your exact weight should be in range between ");
        Serial.print(lower_bound);
        Serial.print(" kgs to ");
        Serial.print(upper_bound);
        Serial.println(" kgs");
      }
      // Calculating BMI

      BMI = ((weight/height)/height)*10000;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Your BMI is :");
      lcd.print(BMI);
      delay(6000);
      Serial.print("Your Accurate BMI is :");
      Serial.println(BMI);
      
    }
    
  }
  
  
  // Code End
}
