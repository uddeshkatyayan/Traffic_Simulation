#ifndef RoadH
#define RoadH

#include <vector>
#include <string>
#include "Vehicle.h"
using namespace std;

class Road {

public:
     Road(int Road_Length, int Road_Width, int Road_Signal, int Road_Id);
     Road();
     Road(const Road &R1);
    Road & operator=(const Road & R1);
     ~Road();
     void printVehicles();
     void flush();
    //  void flush(vector<vector<char>> *vector2d);
     void update();           //re-initializes road to all empty chars and then places each vehicle at its correct position;
     void render();
     void incrementTime();
     void addVehicle(string Vehicle_Type, int Vehicle_Length, int Vehicle_Width, int Vehicle_MaxSpeed, int Vehicle_Max_Acceleration, string Vehicle_Colour);
     void renderVehicles();

    int Length;                     //consider making these private and create getters and setters
    int Signal;
    int Width;
    int Id;
    string SignalState;                      // RED or GREEN are legal values
    string Name;
    vector<Vehicle> VehicleList;
    vector< vector<char> > road;
    vector<vector<int>> roadd;      // -1 <--> ' '; i <--> VehicleList[i].Type[0] for i>=0; -2 <--> signal; 
private:
};

#endif