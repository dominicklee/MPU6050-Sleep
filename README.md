# MPU6050-Sleep
Arduino ESP8266 with MPU6050 interrupt wake. Additional circuit needed to make this work.

Using MPU6050 interrupt *active-low* logic is not possible to wake the ESP after power cycle because the ESP RST is the only way to wake from sleep and that is active-low. By default, MPU starts with a default active-high interrupt. Although the MPU logic can be flipped, it cannot be done before the ESP wakes up and sends preamble.

This is a Github archive of the code that is used to sleep ESP and wake it with MPU:

[https://bit.ly/2Awdq07](https://bit.ly/2Awdq07)

All 3rd party libraries are open-source and credited to their rightful owner.