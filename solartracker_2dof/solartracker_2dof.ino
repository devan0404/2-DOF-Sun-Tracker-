//Two DOF Solar Tracker

#include <Servo.h>

Servo servoH;  // horizontal motor
Servo servoV;  // vertical motor

const int AZIMUTH_SERVO_PIN = 6;
const int ELEVATION_SERVO_PIN = 9;

//Calculating Azimuth and Elevation Angles
float Lati = 12.29 ;
float Longi = 76.61;

int day = 80;       //Day of the year
float time = 6.0;   //Time in 24hr format 

//Calculating the Angles
int posH;
int posV;
float DeclinationA;
float HourA;
float ElevationA;
float AzimuthA;

void setup() {

  Serial.begin(9600);

  servoH.attach(AZIMUTH_SERVO_PIN);  
  servoV.attach(ELEVATION_SERVO_PIN);   

}

void loop() {

  time += 0.05;   // simulate time

  if (time > 18) time = 6;   // reset day

  DeclinationA = 23.45 * sin(radians((360.0/365.0) * (284 + day)));
  HourA = 15 * (time - 12);

  ElevationA = asin(
    sin(radians(Lati)) * sin(radians(DeclinationA)) +
    cos(radians(Lati)) * cos(radians(DeclinationA)) * cos(radians(HourA))
  );
  ElevationA = degrees(ElevationA);

  float sinA = (cos(radians(DeclinationA)) * sin(radians(HourA))) / cos(radians(ElevationA));
  float cosA = (sin(radians(DeclinationA)) - sin(radians(ElevationA)) * sin(radians(Lati))) /(cos(radians(ElevationA)) * cos(radians(Lati)));

  sinA = constrain(sinA, -1, 1);
  cosA = constrain(cosA, -1, 1);

  AzimuthA = degrees(atan2(sinA, cosA));
  if (AzimuthA < 0) AzimuthA += 360;
  if (ElevationA < 0) ElevationA = 0;

  // Horizontal (East → West , 0 -> 180)
  posH = map(AzimuthA, 90, 270, 0, 180);
  posH = constrain(posH, 0, 180);

  // Vertical (South → North , 0 -> 180)
  posV = map(ElevationA, 0, 90, 0, 90);
  posV = constrain(posV, 0, 90);

  servoV.write(posV);
  servoH.write(posH);

  Serial.print("Time: "); Serial.print(time);
  Serial.print(" | H: "); Serial.print(posH);
  Serial.print(" | V: "); Serial.println(posV);

  delay(1500);
}
