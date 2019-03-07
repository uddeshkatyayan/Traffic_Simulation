#ifndef VehicleH
#define VehicleH
#include <vector>
#include <string>
using namespace std;

class Vehicle {

public:
    Vehicle();
    Vehicle(const Vehicle &V1);
    Vehicle & operator=(const Vehicle & V1);
    Vehicle(string Vehicle_Type, int Vehicle_Length, int Vehicle_Width, int Vehicle_MaxSpeed, int Vehicle_Acceleration);
    ~Vehicle();
    void update(string RoadSignalState, int RoadSignal);
    void printParameters();

    string Type;
    int Length;              //consider making these private and create getters and setters
    int Width;
    int MaxSpeed;
    int Acceleration;
    int Id;
    int X;
    int Y;
    int VX;


private:
};

#endif