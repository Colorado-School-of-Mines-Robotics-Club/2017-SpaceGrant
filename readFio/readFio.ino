#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(57600);  // start serial for output
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = beaconHeading(); // receive a byte as character
    Serial.println(i);         // print the character
        

  delay(500);
}


int beaconHeading(){
  Wire.requestFrom(8, 2);    // request 6 bytes from slave device #8
  uint8_t currHeadingI2c[2];
  currHeadingI2c[0] = Wire.read();
  currHeadingI2c[1] = Wire.read();
  short he = (currHeadingI2c[0] << 8) | (currHeadingI2c[1]);
  int beac = (int) he;
  return beac;
  //byte MSB = Wire.read();
  //byte LSB = Wire.read();
  //return (MSB<<8)|LSB;
}

