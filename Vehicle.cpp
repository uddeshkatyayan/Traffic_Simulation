#include <iostream>
#include <string>
#include <vector>
#include "Road.h"
#include "Vehicle.h"
#define DEFAULT_VEHICLE_TYPE "Car";
#define DEFAULT_VEHICLE_LENGTH 2;
#define DEFAULT_VEHICLE_WIDTH 2;
#define DEFAULT_VEHICLE_MAXSPEED 1;
#define DEFAULT_VEHICLE_ACCELERATION 1;
#define DEFAULT_VEHICLE_ID 4544;
#define DEFAULT_VEHICLE_X -DEFAULT_VEHICLE_LENGTH;
#define DEFAULT_VEHICLE_Y 1;
#define DEFAULT_VEHICLE_VX 0;
using namespace std;

Vehicle::Vehicle(){
    this->Type = DEFAULT_VEHICLE_TYPE;
    this->Length = DEFAULT_VEHICLE_LENGTH;
    this->Width = DEFAULT_VEHICLE_WIDTH;
    this->MaxSpeed = DEFAULT_VEHICLE_MAXSPEED;
    this->Acceleration = DEFAULT_VEHICLE_ACCELERATION;
    this->Id = DEFAULT_VEHICLE_ID;
    this->X = DEFAULT_VEHICLE_X;
    this->Y = DEFAULT_VEHICLE_Y;
    this->VX = DEFAULT_VEHICLE_VX;
}

Vehicle::Vehicle(const Vehicle &V1){
    this->Type = V1.Type;
    this->Length = V1.Length;
    this->Width = V1.Width;
    this->MaxSpeed = V1.MaxSpeed;
    this->Acceleration = V1.Acceleration;
    this->Id = V1.Id;
    this->X = V1.X;
    this->Y = V1.Y;
    this->VX = V1.VX;
}

Vehicle & Vehicle::operator=(const Vehicle & V1){
    this->Type = V1.Type;
    this->Length = V1.Length;
    this->Width = V1.Width;
    this->MaxSpeed = V1.MaxSpeed;
    this->Acceleration = V1.Acceleration;
    this->Id = V1.Id;
    this->X = V1.X;
    this->Y = V1.Y;
    this->VX = V1.VX;
    return *this;
}

Vehicle::Vehicle(string Vehicle_Type, int Vehicle_Length, int Vehicle_Width, int Vehicle_MaxSpeed, int Vehicle_Acceleration){
    this->Type = Vehicle_Type;
    this->Length = Vehicle_Length;
    this->Width = Vehicle_Width;
    this->MaxSpeed = Vehicle_MaxSpeed;
    this->Acceleration = Vehicle_Acceleration;

    this->Id = DEFAULT_VEHICLE_ID;
    this->X = DEFAULT_VEHICLE_X;
    this->Y = DEFAULT_VEHICLE_Y;
    this->VX = DEFAULT_VEHICLE_VX
}

Vehicle::~Vehicle(){

}

int Vehicle::nextSpeedState(){
    return 0;
}

int Vehicle::stoppingDistance(){
    
    int distance = 0;
    int speed = VX;
    int distance = 0;
    while(speed!=0){
        distance += speed;
        speed = max(0, speed - Acceleration);
    }

    return distance;
}

void Vehicle::update(vector<vector<char>> road, int RoadSignal, string RoadSignalState){
    switch (nextSpeedState()){
        case 1:
            VX = max(0, min(MaxSpeed, VX + Acceleration));      //clamp values to 0 and MaxSpeed
            break;
        case -1:
            VX = max(0, min(MaxSpeed, VX - Acceleration));      //clamp values to 0 and MaxSpeed
            break;
        case 0:

            break;
        default:  
    }
    X = X + VX;
}

void Vehicle::printParameters(){
  
    cout/*<<"Vehicle_Type: "*/<<this->Type<<endl;
    cout<<"    "<<"Vehicle_Length: "<<this->Length<<endl;
    cout<<"    "<<"Vehicle_Width: "<<this->Width<<endl;
    cout<<"    "<<"Vehicle_MaxSpeed: "<<this->MaxSpeed<<endl;
    cout<<"    "<<"Vehicle_Acceleration: "<<this->Acceleration<<endl;
}

bool Vehicle::isCrashed(){

    return false;
}

// int main(){

//     Vehicle car1("Car", 5, 2, 5, 3);
//     Vehicle car2;
//     car1.printParameters();
//     car2.printParameters();
//     cout<< car2.X<<endl;
//     return 0;
// }