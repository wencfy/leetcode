/**
 * Design Parking System
 * 
 * Design a parking system for a parking lot. The parking lot has three kinds of parking spaces:
 * big, medium, and small, with a fixed number of slots for each size.
 * 
 * Implement the ParkingSystem class:
 * 
 * - ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. The number of slots for each parking space are given as part of the constructor.
 * 
 * - bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot.
 *   carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its carType. If there is no space available, return false, else park the car in that size space and return true.
 */

#include "iostream"
using namespace std;

class ParkingSystem {
private:
    vector<int> leftSlots = {0, 0, 0, 0};
public:
    ParkingSystem(int big, int medium, int small) {
        leftSlots[1] = big;
        leftSlots[2] = medium;
        leftSlots[3] = small;
    }
    
    bool addCar(int carType) {
        if (leftSlots[carType]) {
            leftSlots[carType]--;
            return true;
        } else {
            return false;
        }
    }
};