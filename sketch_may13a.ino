#include <Wire.h>
#include <QMC5883LCompass.h>

QMC5883LCompass compass;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  compass.init();
}

void loop() {
  compass.read();
  float heading = compass.getAzimuth();
  String direction = getDirection(heading);
  Serial.print("Heading: ");
  Serial.print(heading);
  Serial.print(" degrees, Direction: ");
  Serial.println(direction);
  delay(1000);  
}

String getDirection(float heading) {
  if (heading >= 22.5 && heading < 67.5) {
    return "Northeast";
  } else if (heading >= 67.5 && heading < 112.5) {
    return "East";
  } else if (heading >= 112.5 && heading < 157.5) {
    return "Southeast";
  } else if (heading >= 157.5 && heading < 202.5) {
    return "South";
  } else if (heading >= 202.5 && heading < 247.5) {
    return "Southwest";
  } else if (heading >= 247.5 && heading < 292.5) {
    return "West";
  } else if (heading >= 292.5 && heading < 337.5) {
    return "Northwest";
  } else {
    return "North";
  }
}
