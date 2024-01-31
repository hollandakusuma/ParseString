//example parse string

String text ="+CGNSINF: 1,1,20210218113556.000,0.912483,104.505741,22.600,0.00,208.1,1,,1.1,1.4,0.9,,19,7,3,,,41,,";
/*
text is string contain data from GPS
we will parse the string to several parameters:
<GNSS run status>,
<Fix status>,
<UTC date & Time>,
<Latitude>,
<Longitude>,
<MSL Altitude>,
<Speed Over Ground>,
<Course Over Ground>,
<Fix Mode>,
<Reserved1>,
<HDOP>,
<PDOP>,
<VDOP>,
<Reserved2>,
<GNSS Satellites in View>,
<GNSS Satellites Used>,
<GLONASS Satellites Used>,
<Reserved3>,
<C/N0 max>,
<HPA>,
<VPA>
*/

char Dates[20]="2024/04/30 12:05:14";
float lat, lon, msl,speed, degree;
float hdop, vdop, pdop;
byte satellite, gps, glonass;

String result;
int a, b;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("ESP32");

  delay(100);
  Serial.println(text);

  //parse string
  result = text;
  //fix status
  a=result.indexOf(',');
  b=result.indexOf(',',a+1);
  Serial.println(result.substring(a+1,b));
  
  //<UTC date & Time>
a=result.indexOf(',',b+1);
String tanggal = result.substring(b+1,a);
int years = result.substring(b+1,b+5).toInt();
byte months = result.substring(b+5,b+7).toInt();
byte days= result.substring(b+7,b+9).toInt();
byte hours = result.substring(b+9,b+11).toInt();
byte minutes = result.substring(b+11,b+13).toInt();
byte seconds = result.substring(b+13,b+15).toInt();
sprintf(Dates,"%d/%02d/%02d %02d:%02d:%02d",years, months, days, hours,minutes,seconds);
Serial.println(tanggal);
Serial.println(Dates);

//<Latitude>
b=result.indexOf(',',a+1);
lat = result.substring(a+1,b).toFloat();
Serial.println(lat,6);

// <Longitude>
a=result.indexOf(',',b+1);
lon =result.substring(b+1,a).toFloat();
Serial.println(lon, 6);

// <MSL Altitude>
b=result.indexOf(',',a+1);
msl = result.substring(a+1,b).toFloat();
Serial.println(msl,2);

// <Speed Over Ground>
a=result.indexOf(',',b+1);
speed =result.substring(b+1,a).toFloat();
Serial.println(speed, 2);

// <Course Over Ground>
b=result.indexOf(',',a+1);
speed = result.substring(a+1,b).toFloat();
Serial.println(speed,1);

// <Fix Mode>
a=result.indexOf(',',b+1);
Serial.println(result.substring(b+1,a));

// <Reserved1>

// <HDOP>
b=result.indexOf(',',a+2);
hdop = result.substring(a+2,b).toFloat();
Serial.println(hdop,1);

// <PDOP>
a=result.indexOf(',',b+1);
pdop=result.substring(b+1,a).toFloat();
Serial.println(pdop);

// <VDOP>
b=result.indexOf(',',a+1);
vdop = result.substring(a+1,b).toFloat();
Serial.println(vdop,1);

// <Reserved2>

// <GNSS Satellites in View>
a=result.indexOf(',',b+2);
satellite=result.substring(b+2,a).toInt();
Serial.println(satellite);

// <GNSS Satellites Used>
b=result.indexOf(',',a+1);
gps = result.substring(a+1,b).toInt();
Serial.println(gps);

// <GLONASS Satellites Used>
a=result.indexOf(',',b+1);
glonass=result.substring(b+1,a).toInt();
Serial.println(glonass);
}

void loop() {

  }
