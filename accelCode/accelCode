// test_mpu6050.cpp
// Compile with: g++ test_mpu6050.cpp -o test_mpu6050 -lMPU6050 -pthread

#define _USE_MATH_DEFINES
#include "MPU6050.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 0x68 is the default I2C address (AD0 pin LOW)
    // Use 0x69 if AD0 is pulled HIGH
    MPU6050 mpu(0x68);

    cout << "MPU6050 Tester - Raw Accelerometer & Gyroscope Data" << endl;
    cout << "=====================================================" << endl;

    float ax, ay, az;
    float gx, gy, gz;
    double complementaryAngle = 0.0;

    float filteredAx = 0.0f;
    float filteredAy = 0.0f;
    float filteredAz = 0.0f;
    float alpha = 0.15f;

    
    while (true) {
        mpu.getAccel(&ax, &ay, &az);
        mpu.getGyro(&gx, &gy, &gz);

	filteredAx = alpha * ax + (1.0 - alpha) * filteredAx;
	filteredAy = alpha * ay + (1.0 - alpha) * filteredAy;
	filteredAz = alpha * az + (1.0 - alpha) * filteredAz;
	
	// Get accelorometer measurements (may need to lowpass this)
	cout << "\n--- Accelerometer (g) ---" << endl;
        cout << "  X: " << ax << endl;
        cout << "  Y: " << ay << endl;
        cout << "  Z: " << az << endl;

	cout << "------------------------------------------------\n";
	cout << "Filtered X: " << filteredAx << endl;
	cout << "Filtered Y: " << filteredAy << endl;
	cout << "Filtered Z: " << filteredAz << endl;

	// Calculate the accelorometer angle presumably through trig
	double accelAngleY = atan2(filteredAy, sqrt((filteredAx*filteredAx) + (filteredAz*filteredAz))) * 180 / M_PI;
	
	// Mutliply the final result by the weight you assign
	double accelWeight = 0.20;
	double finalAccelAngleY = accelAngleY * accelWeight; 
	
	
	// get gyroscope measurements
        cout << "--- Gyroscope (deg/s) ---" << endl;
        cout << "  Roll:  " << gx << endl;
        cout << "  Pitch: " << gy << endl;
        cout << "  Yaw:   " << gz << endl;


	// multiply by delta time, whatever that may be
        double dt = 0.1;
	double gyroPitchInit = gy * dt;
	
	// add the value of complementary angle (initially zero) to the result
	double gyroPitch2 = gyroPitchInit + complementaryAngle;
	
	// multiply the result by the gyro weight
	double gyroWeight = 1.0 - accelWeight;
	double gyroPitchFinal = gyroPitch2 * gyroWeight;
	
	// add the accel values and the gyro values together
        complementaryAngle = gyroPitchFinal + finalAccelAngleY;

	cout << complementaryAngle << endl;
        usleep(100000); // 100ms (~10Hz)
    }

    return 0;
}
