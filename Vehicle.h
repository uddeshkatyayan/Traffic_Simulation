#ifndef VehicleH
#define VehicleH

#include <vector>
#include <string>
using namespace std;

struct nextVehicleParams
{       
    int index;
    int distance;
};

class Vehicle {

public:
    Vehicle();
    Vehicle(const Vehicle &V1);
    Vehicle & operator=(const Vehicle & V1);
    Vehicle(string Vehicle_Type, int Vehicle_Length, int Vehicle_Width, int Vehicle_MaxSpeed, int Vehicle_Max_Acceleration);
    ~Vehicle();
    void update(vector<vector<int>> roadd, vector<Vehicle> VehicleList, int RoadSignal, string RoadSignalState);
    void printParameters();
    // void setX(int x, vector<vector<int>> roadd);
    // void setY(int y, vector<vector<int>> roadd);
    bool isCrashed();
    int nextSpeedState(int nextVehicle, int nextDistance, vector<Vehicle> VehicleList);    //returns 1, -1 or 0 corresponding to states "INCREMENT", "DECREMENT" or "CONSTANT"
    int stoppingDistance();
    int futureStoppingDistance();
    struct nextVehicleParams nearestVehicle(vector<vector<int>> roadd);
    
    string Type;
    int Length;              //consider making these private and create getters and setters
    int Width;
    int MaxSpeed;
    int Max_Acceleration;
    int AX;
    int Id;
    int X;
    int Y;
    int VX;


private:
};

#endif