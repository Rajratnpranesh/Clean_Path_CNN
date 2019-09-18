/* 
 *  This source code is for project on Air Quality Index Measurement and display System.
 *   
 *  Date - 30-12-2018 10:49 AM
 *  @Raj Ratn Pranesh
 *  @Version :- AQI_MS_V00
 *  @Updated :- None till now.
 */

 float PM10c=0,PM25c=0,COc=0,NO2c=0,SO2c=0; // variable to store pollutant concentration
 int PM10si=0,PM25si=0,COsi=0,NO2si=0,SO2si=0; // variable to store pollutant sub- index

 int AQI=0; //variable to store Air Quality Index

 const int humidity_sensor=7; // Pin number for humidity sensor
 float humidity=0.0; // variable to store humidity

 const int temp_sensor=A1; // Pin number of temperature sensor
 float tempc;  //variable to store temperature in degree Celsius
 float tempf;  //variable to store temperature in Fahreinheit 
 float vout;  //temporary variable to hold sensor reading
void setup() 
{
  Serial.begin(4800);
  pinMode(A0,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A13,OUTPUT);
  pinMode(A14,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(humidity_sensor,INPUT);
  analogWrite(6,0);
  analogWrite(5,255);
  analogWrite(A0,0);
  analogWrite(A2,255);

}

void loop() 
{
  clearscreen();
  Serial.println("******************************************************");
  temperature();
  Serial.println("******************************************************");
  humidity_calc();
  Serial.println("******************************************************");
  concPM10();
  concPM25();
  concCO();
  concSO2();
  concNO2();
  Serial.println("******************************************************");
  getAQI();
  Serial.println("******************************************************");
  delay(5000);
  
  
}

//======================================== Temperature Measurement =============================================

void temperature() 
{
vout=analogRead(temp_sensor);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
Serial.print("Temp in Celcius :- ");
Serial.println(tempc);
tempf=(vout*1.8)+32; // Converting to Fahrenheit 
Serial.print("Temp in Ferenhiet :- ");
Serial.println(tempf);
}

//======================================== Humidity Measurement =============================================

void humidity_calc()
{
  vout=analogRead(humidity_sensor);
  humidity=map(vout,0,1023,20,95);
  Serial.print("Raw data :-  ");
  Serial.println(vout);
  Serial.print("Humidity :- " );
  Serial.println(humidity);
}

//========================================== Calculation of AQI ================================================

void getAQI()
{
  //to be updated
  AQI=PM10si>PM25si?(PM10si>COsi?(PM10si >NO2si ? (PM10si > SO2si ? PM10si : SO2si) : (NO2si > SO2si ?NO2si : SO2si)):(COsi > NO2si ? (COsi > SO2si ? COsi : SO2si) : (NO2si > SO2si ? NO2si : SO2si))): (PM25si>COsi?(PM25si > NO2si ? (PM25si > SO2si ? PM25si : SO2si) : (NO2si > SO2si ? NO2si : SO2si)):(COsi > NO2si ? (COsi > SO2si? COsi: SO2si) : (NO2si > SO2si ? NO2si : SO2si))) ;
  Serial.print("                  AQI =  ");
  Serial.println(  AQI);    
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ * Functions for Measuring Values of different environmental Parameters * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//========================== Mesuremenent of PM10 concentration and it`s sub index ===========================

void concPM10()
{
  // To be updated

  //------- Calculating sub index of PM10
  if(PM10c<=100)
  {
    PM10si=PM10c;
  }
  else if(PM10c>100 && PM10c<=250)
  {
    PM10si=100+(PM10c-100)*100/150;
  }
  else if(PM10c>250 && PM10c<=350)
  {
    PM10si=200+(PM10c-250);
  }
  else if(PM10c>350 && PM10c<=430)
  {
    PM10si=300+(PM10c-350)*100/80;
  }
  else
  {
    PM10si=400+(PM10c-430)*(100/80);
  }

  Serial.print("Concentration of PM10 = ");
  Serial.print(PM10c);
  Serial.print("  Sub-index of PM10 = ");
  Serial.println(PM10si);
}
//========================== Mesuremenent of PM2.5 concentration and it`s sub index ===========================

void concPM25()
{
  // To be updated

   //------- Calculating sub index of PM2.5
  if(PM25c<=30)
  {
    PM25si=PM25c*50/30;
  }
  else if(PM25c>30 && PM25c<=60)
  {
    PM25si=50+(PM25c-30)*50/30;
  }
  else if(PM25c>60 && PM25c<=90)
  {
    PM25si=100+(PM25c-60)*100/30;
  }
  else if(PM25c>90 && PM25c<=120)
  {
    PM25si=200+(PM25c-90)*100/30;
  }
   else if(PM25c>120 && PM25c<=250)
  {
    PM25si=300+(PM25c-120)*100/130;
  }
  else
  {
    PM25si=400+(PM25c-250)*(100/130);
  }

  Serial.print("Concentration of PM2.5= ");
  Serial.print(PM25c);
  Serial.print("  Sub-index of PM2.5= ");
  Serial.println(PM25si);
}

//========================== Mesuremenent of CO concentration and it`s sub index ===========================

void concCO()
{
  // To be updated

 //------- Calculating sub index of CO
  if(COc<=1)
  {
    COsi=COc*50;
  }
  else if(COc>1 && COc<=2)
  {
    COsi=50+(COc-1)*50;
  }
  else if(COc>2 && COc<=10)
  {
    COsi=100+(COc-2)*100/8;
  }
  else if(COc>10 && COc<=17)
  {
    COsi=200+(COc-10)*100/7;
  }
   else if(COc>17 && COc<=34)
  {
    COsi=300+(COc-17)*100/17;
  }
  else
  {
    COsi=400+(COc-34)*(100/17);
  }

  Serial.print("Concentration of CO   = ");
  Serial.print(COc);
  Serial.print("  Sub-index of CO   = ");
  Serial.println(COsi);
}

//========================== Mesuremenent of SO2 concentration and it`s sub index ===========================

void concSO2()
{
  // To be updated

  //------- Calculating sub index of SO2
  if(SO2c<=40)
  {
    SO2si=SO2c*50/40;
  }
  else if(SO2c>40 && SO2c<=80)
  {
    SO2si=50+(SO2c-40)*50/40;
  }
  else if(SO2c>80 && SO2c<=380)
  {
    SO2si=100+(SO2c-80)*100/300;
  }
  else if(SO2c>380 && SO2c<=800)
  {
    SO2si=200+(SO2c-380)*100/420;
  }
   else if(SO2c>800 && SO2c<=1600)
  {
    SO2si=300+(SO2c-800)*100/800;
  }
  else
  {
    SO2si=400+(SO2c-1600)*(100/800);
  }

  Serial.print("Concentration of SO2  = ");
  Serial.print(SO2c);
  Serial.print("  Sub-index of SO2  = ");
  Serial.println(SO2si);
  
}



//========================== Mesuremenent of NO2 concentration and it`s sub index ===========================

void concNO2()
{
  // To be updated

 
  //------- Calculating sub index of NO2
  if(NO2c<=40)
  {
    NO2si=NO2c*50/40;
  }
  else if(NO2c>40 && NO2c<=80)
  {
    NO2si=50+(NO2c-40)*50/40;
  }
  else if(NO2c>80 && NO2c<=180)
  {
    NO2si=100+(NO2c-80);
  }
  else if(NO2c>180 && NO2c<=280)
  {
    NO2si=200+(NO2c-180);
  }
   else if(NO2c>280 && NO2c<=400)
  {
    NO2si=300+(NO2c-280)*100/120;
  }
  else
  {
    NO2si=400+(NO2c-400)*(100/120);
  }

  Serial.print("Concentration of NO2  = ");
  Serial.print(NO2c);
  Serial.print("  Sub-index of NO2  = ");
  Serial.println(NO2si);
}


//=============================================== This function clears the serial monitor screen =============================================
// This function may not work properly in some cases, then to rectify increase upper limit of variable i.

void clearscreen()
{
  int i;
  for(i=0;i<=35;i++)
  Serial.println(" ");
}

