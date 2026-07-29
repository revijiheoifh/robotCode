// test_mpu6050.cpp
// Compile with: g++ test_mpu6050.cpp -o test_mpu6050 -lMPU6050 -pthread

#define _USE_MATH_DEFINES
#include "MPU6050.h"
#include <iostream>
#include <cmath>

using namespace std;

float lpFilterAccel(float alpha, float valueAtAxis, float previousFilteredValue);
double calculateAngle(float angleBeingCalculated, float otherAngle, float otherAngle2);
double complementaryAngleCalc(double accelAngle, double accelWeight, double gyroAngle, double complementaryAngle);

int main() {
    // 0x68 is the default I2C address (AD0 pin LOW)
    // Use 0x69 if AD0 is pulled HIGH
    MPU6050 mpu(0x68);

    cout << "MPU6050 Tester - Raw Accelerometer & Gyroscope Data" << endl;
    cout << "=====================================================" << endl;

    float ax, ay, az;
    float gx, gy, gz;
    double complementaryAngle = 0.0f;

    float filteredAx = 0.0f;
    float filteredAy = 0.0f;
    float filteredAz = 0.0f;
    float alpha = 0.15f;

    double compAngleValues[10];
    double compAngleAverage = 0.0f;

    while (true) {
        mpu.getAccel(&ax, &ay, &az);
        mpu.getGyro(&gx, &gy, &gz);

	filteredAx = lpFilterAccel(alpha, ax, filteredAx);
	filteredAy = lpFilterAccel(alpha, ay, filteredAy);
	filteredAz = lpFilterAccel(alpha, az, filteredAz);

	double accelAngleY = calculateAngle(filteredAy, filteredAx, filteredAz);
	double accelWeight = 0.01;

	complementaryAngle = round(complementaryAngleCalc(accelAngleY, accelWeight, gy, complementaryAngle));

	for(int i = 0; i < 10; i++)
	{
	  compAngleValues[i] = complementaryAngle;
          compAngleAverage += compAngleValues[i];
	}

	compAngleAverage = round(compAngleAverage / 10);


	cout << compAngleAverage << endl;
        usleep(100000); // 100ms (~10Hz) 
    }

    return 0;
}

float lpFilterAccel(float alpha, float valueAtAxis, float previousFilteredValue)
{
  return alpha * valueAtAxis + (1.0 - alpha) * previousFilteredValue;
}

double calculateAngle(float angleBeingCalculated, float otherAngle, float otherAngle2)
{
  return atan2(angleBeingCalculated, sqrt((otherAngle * otherAngle) + (otherAngle2 * otherAngle2))) * 180 / M_PI;
}

double complementaryAngleCalc(double accelAngle, double accelWeight, double gyroAngle, double complementaryAngle)
{
  double finalAccelAngle = accelAngle * accelWeight;
  double dt = 0.1; // this value is hard-coded for now, will have to change later

  double gyroAngleInit = gyroAngle * dt;
  double gyroAngle2 = gyroAngleInit + complementaryAngle;
  
  double gyroWeight = 1.0 - accelWeight;
  double gyroAngleFinal = gyroAngle2 * gyroWeight;

  complementaryAngle = gyroAngleFinal + finalAccelAngle;

  return complementaryAngle;
}
