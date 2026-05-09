// test_mpu6050.cpp
// Compile with: g++ test_mpu6050.cpp -o test_mpu6050 -li2c

#include "MPU6050.h"

int main() {
    // 0x68 is the default I2C address (AD0 pin LOW)
    // Use 0x69 if AD0 is pulled HIGH
    MPU6050 mpu(0x68);

    std::cout << "MPU6050 Tester - Raw Accelerometer & Gyroscope Data" << std::endl;
    std::cout << "=====================================================" << std::endl;

    float ax, ay, az;
    float gx, gy, gz;

    while (true) {
        mpu.getAccel(&ax, &ay, &az);
        mpu.getGyro(&gx, &gy, &gz);

        std::cout << "\n--- Accelerometer (g) ---" << std::endl;
        std::cout << "  X: " << ax << std::endl;
        std::cout << "  Y: " << ay << std::endl;
        std::cout << "  Z: " << az << std::endl;

        std::cout << "--- Gyroscope (deg/s) ---" << std::endl;
        std::cout << "  Roll:  " << gx << std::endl;
        std::cout << "  Pitch: " << gy << std::endl;
        std::cout << "  Yaw:   " << gz << std::endl;

        usleep(100000); // 100ms (~10Hz)
    }

    return 0;
}
