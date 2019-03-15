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
    void update(vector<vector<char>> road, int RoadSignal, string RoadSignalState);
    void printParameters();
    bool isCrashed();
    int nextSpeedState();    //returns 1, -1 or 0 corresponding to states "INCREMENT", "DECREMENT" or "CONSTANT"
    int stoppingDistance();
    
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