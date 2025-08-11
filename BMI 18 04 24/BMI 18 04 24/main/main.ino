  // @Nilanjan NBhattacharjee's declairation for System Design
//#define gender 4 // value should be either 1 or 0; female = 1; male = 0;
#include <ESP8266WiFi.h>
int gender = D4;
int db[60][4];
int measuredHeight;
float measuredWeight;

const int H = 137;
float BMI;

// @ANG Sir's Weight Calculating method's declairation     
#include <LiquidCrystal_I2C.h>
#include "HX711.h"
//LiquidCrystal lcd(12,11,5,4,3,2); 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
const int DOUT = D7; 
const int CLK = D8; 
HX711 scale;
float weight; 
float calibration_factor = 36000  ; // for me this value works just perfect 419640 

// @ANG Sir's Height Calculating method's declairation
#include <Wire.h>
float trigPin = D5;
float echoPin = D6;
const float a=199;
const float b=74;
float z;
long duration;
int distanceCm, distanceInch;

String apiKey = "MRH1HG5AAHVJBJU5";     //  Enter your Write API key here
const char *ssid =  "AndroidAP";     // Enter your WiFi Name
const char *pass =  "anirbanghosal"; // Enter your WiFi Password
const char* server = "api.thingspeak.com";
WiFiClient client;


void setup(){
  Serial.begin (115200);
  lcd.init();                    
  lcd.backlight();

  Serial.println("Connecting to ");
//  lcd.print("Connecting.... ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
   // lcd.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  delay(5000);
  Serial.println(WiFi.localIP());
  delay(5000);

 
  // @Nilanjan NBhattacharjee's declairation for System Design
  // Data Entry start
  db[0][0] = 285, db[0][1] = 349, db[0][2] = 285, db[0][3] = 349;
  db[1][0] = 285, db[1][1] = 349, db[1][2] = 285, db[1][3] = 349;
  db[2][0] = 308, db[2][1] = 376, db[2][2] = 308, db[2][3] = 381;
  db[3][0] = 308, db[3][1] = 376, db[3][2] = 308, db[3][3] = 381;
  db[4][0] = 308, db[4][1] = 376, db[4][2] = 308, db[4][3] = 381;
  db[5][0] = 326, db[5][1] = 399, db[5][2] = 335, db[5][3] = 408;
  db[6][0] = 326, db[6][1] = 399, db[6][2] = 335, db[6][3] = 408;
  db[7][0] = 349, db[7][1] = 426, db[7][2] = 358, db[7][3] = 439;
  db[8][0] = 349, db[8][1] = 426, db[8][2] = 358, db[8][3] = 439;
  db[9][0] = 349, db[9][1] = 426, db[9][2] = 358, db[9][3] = 439;
  db[10][0] = 364, db[10][1] = 449, db[10][2] = 385, db[10][3] = 467;
  db[11][0] = 364, db[11][1] = 449, db[11][2] = 385, db[11][3] = 467;
  db[12][0] = 390, db[12][1] = 476, db[12][2] = 408, db[12][3] = 499;
  db[13][0] = 390, db[13][1] = 476, db[13][2] = 408, db[13][3] = 499;
  db[14][0] = 390, db[14][1] = 476, db[14][2] = 408, db[14][3] = 499;
  db[15][0] = 408, db[15][1] = 499, db[15][2] = 431, db[15][3] = 530;
  db[16][0] = 408, db[16][1] = 499, db[16][2] = 431, db[16][3] = 530;
  db[17][0] = 431, db[17][1] = 526, db[17][2] = 458, db[17][3] = 558;
  db[18][0] = 431, db[18][1] = 526, db[18][2] = 458, db[18][3] = 558;
  db[19][0] = 431, db[19][1] = 526, db[19][2] = 458, db[19][3] = 558;
  db[20][0] = 449, db[20][1] = 549, db[20][2] = 481, db[20][3] = 589;
  db[21][0] = 449, db[21][1] = 549, db[21][2] = 481, db[21][3] = 589;
  db[22][0] = 472, db[22][1] = 576, db[22][2] = 508, db[22][3] = 616;
  db[23][0] = 472, db[23][1] = 576, db[23][2] = 508, db[23][3] = 616;
  db[24][0] = 472, db[24][1] = 576, db[24][2] = 508, db[24][3] = 616;
  db[25][0] = 490, db[25][1] = 599, db[25][2] = 530, db[25][3] = 648;
  db[26][0] = 490, db[26][1] = 599, db[26][2] = 530, db[26][3] = 648;
  db[27][0] = 490, db[27][1] = 599, db[27][2] = 530, db[27][3] = 648;
  db[28][0] = 512, db[28][1] = 626, db[28][2] = 553, db[28][3] = 680;
  db[29][0] = 512, db[29][1] = 626, db[29][2] = 553, db[29][3] = 680;
  db[30][0] = 530, db[30][1] = 648, db[30][2] = 580, db[30][3] = 707;
  db[31][0] = 530, db[31][1] = 648, db[31][2] = 580, db[31][3] = 707;
  db[32][0] = 530, db[32][1] = 648, db[32][2] = 580, db[32][3] = 707;
  db[33][0] = 553, db[33][1] = 676, db[33][2] = 603, db[33][3] = 739;
  db[34][0] = 553, db[34][1] = 676, db[34][2] = 603, db[34][3] = 739;
  db[35][0] = 571, db[35][1] = 698, db[35][2] = 630, db[35][3] = 766;
  db[36][0] = 571, db[36][1] = 698, db[36][2] = 630, db[36][3] = 766;
  db[37][0] = 571, db[37][1] = 698, db[37][2] = 630, db[37][3] = 766;
  db[38][0] = 594, db[38][1] = 726, db[38][2] = 653, db[38][3] = 798;
  db[39][0] = 594, db[39][1] = 726, db[39][2] = 653, db[39][3] = 798;
  db[40][0] = 612, db[40][1] = 748, db[40][2] = 676, db[40][3] = 830;
  db[41][0] = 612, db[41][1] = 748, db[41][2] = 676, db[41][3] = 830;
  db[42][0] = 612, db[42][1] = 748, db[42][2] = 676, db[42][3] = 830;
  db[43][0] = 635, db[43][1] = 775, db[43][2] = 703, db[43][3] = 857;
  db[44][0] = 635, db[44][1] = 775, db[44][2] = 703, db[44][3] = 857;
  db[45][0] = 653, db[45][1] = 798, db[45][2] = 726, db[45][3] = 889;
  db[46][0] = 653, db[46][1] = 798, db[46][2] = 726, db[46][3] = 889;
  db[47][0] = 653, db[47][1] = 798, db[47][2] = 726, db[47][3] = 889;
  db[48][0] = 676, db[48][1] = 825, db[48][2] = 753, db[48][3] = 916;
  db[49][0] = 676, db[49][1] = 825, db[49][2] = 753, db[49][3] = 916;
  db[50][0] = 694, db[50][1] = 848, db[50][2] = 775, db[50][3] = 948;
  db[51][0] = 694, db[51][1] = 848, db[51][2] = 775, db[51][3] = 948;
  db[52][0] = 694, db[52][1] = 848, db[52][2] = 775, db[52][3] = 948;
  db[53][0] = 716, db[53][1] = 875, db[53][2] = 798, db[53][3] = 980;
  db[54][0] = 716, db[54][1] = 875, db[54][2] = 798, db[54][3] = 980;
  db[55][0] = 716, db[55][1] = 875, db[55][2] = 798, db[55][3] = 980;
  db[56][0] = 735, db[56][1] = 898, db[56][2] = 825, db[56][3] = 1006;
  db[57][0] = 735, db[57][1] = 898, db[57][2] = 825, db[57][3] = 1006;
  db[58][0] = 757, db[58][1] = 925, db[58][2] = 848, db[58][3] = 1038;  
  // Data entry stop
// @ANG Sir's Weight Calculating method's declairation
  scale.begin(DOUT, CLK);
  //lcd.begin(16,2);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);

  // @ANG Sir's Height Calculating method's declairation
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(gender,INPUT);
  
  
}

void loop()
{
  
  /* DEBUG AREA
    printDB(db, 137, 139) ;
  
  */
  
   
   
  measuredHeight = getHeight();
  measuredWeight = getWeight();
  
  printResult (db, measuredHeight, measuredWeight, gender);


//  printResult(db, 137, 85.8, 0);
  Serial.println();
  Serial.println();
  delay(1000);
  /*
    Serial.println("Enter Height");
  while(Serial.available() == 0){}
  measuredHeight = Serial.parseInt();
  Serial.println(measuredHeight);
  
  Serial.println("Enter Weight");
  while(Serial.available() == 0){}
  measuredWeight = Serial.parseFloat();
  Serial.println(measuredWeight);
  
  Serial.println("Enter Gender");
  while(Serial.available() == 0){}
  gender = Serial.read();
  Serial.println(gender);
  */

  //delay(1000);

  if (client.connect(server,80))   
                      {  
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(measuredHeight);
                             postStr += "\r\n\r\n";
                             postStr +="&field2=";
                             postStr += String(measuredWeight);
                             postStr += "\r\n\r\n";
                             postStr +="&field3=";
                             postStr += String(BMI);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
                             //Serial.print("Air Quality: ");
                             //Serial.print(temperature);
                             Serial.println(" Height.Send to Thingspeak.");

                            // String postStr = apiKey;
                            // postStr +="&field2=";
                             //postStr += String(tdsValue);
                             //postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
                             //Serial.print("Air Quality: ");
                             //Serial.print(tdsValue);
                             Serial.println(" Weight.Send to Thingspeak.");

                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
                             //Serial.print("Air Quality: ");
                             //Serial.print(tdsValue);
                             Serial.println(" BMI.Send to Thingspeak.");
                        }
}
 
