#include "MPU6050.h"
 
const uint8_t MPU_addr=0x68; // I2C address of the MPU-6050
 
MPU6050 testUnit(MPU_addr);
 
const uint8_t threshold = 3;
const uint8_t duration = 40;

void setupMotionInt(void);
 
void setup() {
Wire.begin();
Serial.begin(115200);
testUnit.setIntMotionEnabled(false);  //stop  subsequent resets

Serial.println("I'm Awake!");
Serial.print("Motion detect Status : "); Serial.println(testUnit.getMotionStatus(),BIN);

Serial.println("Going to sleep...");
delay(1000);
Serial.println("3...");
delay(1000);
Serial.println("2...");
delay(1000);
Serial.println("1...");

setupMotionInt();
ESP.deepSleep(0);
}
 
void loop() {
 
}
 
void setupMotionInt(){
 
testUnit.initialize();
Serial.println(testUnit.testConnection());
 
// Ensure the accelerometer is running
testUnit.setSleepEnabled(false);
testUnit.setWakeCycleEnabled(false);
testUnit.setStandbyXAccelEnabled(false);
testUnit.setStandbyYAccelEnabled(false);
testUnit.setStandbyZAccelEnabled(false);
 
//Set the accelerometer HPF to reset settings
testUnit.setDHPFMode(MPU6050_DHPF_RESET);
 
//Set the accelerometer LPF to 256Hz Bandwidth
testUnit.setDLPFMode(MPU6050_DLPF_BW_256);
 
//Enable the motion interrupt
testUnit.setIntEnabled(0b00000000);
testUnit.setIntMotionEnabled(true);
 
//Set the motion detection duration
testUnit.setMotionDetectionDuration(duration); //Duration in ms
 
//Set the motion detection threshold
testUnit.setMotionDetectionThreshold(threshold); // Threshold in 2mg
 
//1 ms delay
delay(1);
 
//Set the accelerometer HPF to HOLD settings
testUnit.setDHPFMode(MPU6050_DHPF_HOLD);
 
// Set the wakeup frequency
testUnit.setWakeFrequency(MPU6050_WAKE_FREQ_5);
testUnit.setStandbyXGyroEnabled(true);
testUnit.setStandbyYGyroEnabled(true);
testUnit.setStandbyZGyroEnabled(true);
 
// Enable cycle mode
testUnit.setWakeCycleEnabled(true);

testUnit.setInterruptLatch(0);  //0 = 50us-pulse, 1 = latch-until-int-cleared
testUnit.setInterruptLatchClear(0); //0 = status-read-only, 1 = any-register-read
testUnit.setInterruptDrive(0);  //0 = pull-pull, 1 = open-drain
testUnit.setInterruptMode(0); //0 = active-high, 1 = active-low
}
