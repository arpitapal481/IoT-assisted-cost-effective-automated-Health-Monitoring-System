int getHeight(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.0340 / 2;
  distanceInch = duration * 0.01330 / 2;
  z= a-distanceCm ; 
  Serial.println(z);
  //Serial.println(b-distanceInch);
  Serial.println(distanceCm);
 // Serial.println(distanceInch);
//  delay(1000);
   return (int) z;
}
