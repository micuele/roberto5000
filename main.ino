#include "Adafruit_VL53L0X.h"
//#include "Driver Motor"

Adafruit_VL53L0X s1 = Adafruit_VL53L0X();
Adafruit_VL53L0X s2 = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!(s1.begin() && s2.begin())) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
  // start continuous ranging
  s1.startRangeContinuous();
  s2.startRangeContinuous();

}

void loop() {
if (s1.isRangeComplete() && s2.isRangeComplete()) {
    
    Serial.println(s1.readRange());
    Serial.print("Distance in mm: ");
    
    Serial.println(s2.readRange());
    Serial.print("Distance in mm: ");
  }
}
