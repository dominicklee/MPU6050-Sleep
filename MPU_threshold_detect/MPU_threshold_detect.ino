#include "MPU6050.h"
 
const uint8_t MPU_addr=0x68; // I2C address of the MPU-6050
 
MPU6050 testUnit(MPU_addr);
 
void setup() {
uint8_t threshold = 1;
uint8_t duration = 1;
 
Wire.begin();
Serial.begin(115200);
testUnit.initialize();
Serial.println(testUnit.testConnection());
 
Serial.print("Current Motion Settings: Threshold: ");Serial.println(testUnit.getMotionDetectionThreshold());
Serial.print("Duration : ");Serial.println(testUnit.getMotionDetectionDuration());
Serial.print("Enabled : ");Serial.println(testUnit.getIntMotionEnabled());
 
testUnit.setMotionDetectionThreshold(threshold); // Threshold in 2mg
testUnit.setMotionDetectionDuration(duration); //Duration in ms
testUnit.setIntMotionEnabled(true);
 
Serial.print("Current Motion Settings: Threshold: ");Serial.println(testUnit.getMotionDetectionThreshold());
Serial.print("Duration : ");Serial.println(testUnit.getMotionDetectionDuration());
Serial.print("Enabled : ");Serial.println(testUnit.getIntMotionEnabled());
}
 
void loop() {
 
Serial.print("Motion detect Status : "); Serial.println(testUnit.getMotionStatus(),BIN);
delay(500); // Wait 5 seconds and scan again
}
