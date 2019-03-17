#include <iostream>
#include <string>
#include <vector>
#include "Road.h"
#include "Vehicle.h"
#define DEFAULT_VEHICLE_TYPE "Car";
#define DEFAULT_VEHICLE_LENGTH 2;
#define DEFAULT_VEHICLE_WIDTH 2;
#define DEFAULT_VEHICLE_MAXSPEED 1;
#define DEFAULT_VEHICLE_MAX_ACCELERATION 1;
#define DEFAULT_VEHICLE_ID 4544;
#define DEFAULT_VEHICLE_X -DEFAULT_VEHICLE_LENGTH;
#define DEFAULT_VEHICLE_Y 1;
#define DEFAULT_VEHICLE_VX 0;
#define DEFAULT_VEHICLE_AX 0;
using namespace std;




Vehicle::Vehicle(){
    this->Type = DEFAULT_VEHICLE_TYPE;
    this->Length = DEFAULT_VEHICLE_LENGTH;
    this->Width = DEFAULT_VEHICLE_WIDTH;
    this->MaxSpeed = DEFAULT_VEHICLE_MAXSPEED;
    this->Max_Acceleration = DEFAULT_VEHICLE_MAX_ACCELERATION;
    this->Id = DEFAULT_VEHICLE_ID;
    this->X = DEFAULT_VEHICLE_X;
    this->Y = DEFAULT_VEHICLE_Y;
    this->VX = DEFAULT_VEHICLE_VX;
    this->VX = DEFAULT_VEHICLE_AX;
}

Vehicle::Vehicle(const Vehicle &V1){
    this->Type = V1.Type;
    this->Length = V1.Length;
    this->Width = V1.Width;
    this->MaxSpeed = V1.MaxSpeed;
    this->Max_Acceleration = V1.Max_Acceleration;
    this->Id = V1.Id;
    this->X = V1.X;
    this->Y = V1.Y;
    this->VX = V1.VX;
    this->AX = V1.AX;
}

Vehicle & Vehicle::operator=(const Vehicle & V1){
    this->Type = V1.Type;
    this->Length = V1.Length;
    this->Width = V1.Width;
    this->MaxSpeed = V1.MaxSpeed;
    this->Max_Acceleration = V1.Max_Acceleration;
    this->Id = V1.Id;
    this->X = V1.X;
    this->Y = V1.Y;
    this->VX = V1.VX;
    this->AX = V1.AX;
    return *this;
}

Vehicle::Vehicle(string Vehicle_Type, int Vehicle_Length, int Vehicle_Width, int Vehicle_MaxSpeed, int Vehicle_Max_Acceleration){
    this->Type = Vehicle_Type;
    this->Length = Vehicle_Length;
    this->Width = Vehicle_Width;
    this->MaxSpeed = Vehicle_MaxSpeed;
    this->Max_Acceleration = Vehicle_Max_Acceleration;

    this->Id = DEFAULT_VEHICLE_ID;
    this->X = DEFAULT_VEHICLE_X;
    this->Y = DEFAULT_VEHICLE_Y;
    this->VX = DEFAULT_VEHICLE_VX
    this->AX = DEFAULT_VEHICLE_AX
}

Vehicle::~Vehicle(){

}

int Vehicle::nextSpeedState(int nextVehicle, int nextDistance, vector<Vehicle> VehicleList){

    int ar, vr, xr;
    int a;

    if (nextVehicle >=0){
        xr = VehicleList[nextVehicle].X - this->X - this->Length;
        vr = VehicleList[nextVehicle].VX - this->VX;
    }else if (nextVehicle == -2){
        xr =  nextDistance;
        vr =  - this->VX;
    }else{
        xr = 100000;
        vr = - this->VX;
    }

    int increasedSpeed = min(MaxSpeed ,VX+ Max_Acceleration) ;

    int d = stoppingDistance();
    int fd = futureStoppingDistance();

    // cout<<d<<"<-d nextD, fd, iSpd-> "<<nextDistance<<", "<<fd<<", "<<increasedSpeed<<endl;
    if (nextDistance > fd+increasedSpeed){
        ar = -Max_Acceleration;
    }else if(nextDistance < d-VX){
        ar = Max_Acceleration;
    }else{
        ar = min(max(-Max_Acceleration,-vr),Max_Acceleration);
    }

    if(VX==0)ar = -nextDistance;

    a=AX-ar;
    // cout<<nextVehicle<<" <-nextVeh  a,ar,VX,vr-> "<<a<<", "<<ar<<", "<<VX<<", "<<vr<<endl;
    return min(max(-Max_Acceleration, a),Max_Acceleration);
}

int Vehicle::stoppingDistance(){
    
    int distance = 0;
    // int speed = min(MaxSpeed ,VX+ Max_Acceleration) ;
    int speed = min(MaxSpeed ,VX+ Max_Acceleration) ;
    while(speed!=0){
        speed = max(0, speed - Max_Acceleration);
        distance += speed;
    }

    return distance;
}

int Vehicle::futureStoppingDistance(){
    
    int distance = 0;
    // int speed = min(MaxSpeed ,VX+ Max_Acceleration) ;
    int speed = VX ;
    while(speed!=0){
        speed = max(0, speed - Max_Acceleration);
        distance += speed;
    }

    return distance;
}

struct nextVehicleParams Vehicle::nearestVehicle(vector<vector<int>> roadd){
    int nextIndex, selfIndex;
    selfIndex = roadd[Y][X];
    // cout<<selfIndex<<endl;
    nextIndex = -1;
    int flag = -1;
    int f=-5;
    for (int i = X+Length ; (i<roadd[0].size())&&(flag==-1); i++ ){
        f=-8;
        for(int j = Y; j<Y + Width; j++){
            if (roadd[j][i] != -1){
                flag = i;
                nextIndex = roadd[j][i];
                // cout<<nextIndex<<" "<<i<<" "<<j<<endl;
                break;
            } 
        }
    }
    // cout<<"flag: "<<flag<<endl;
    // cout<<"nextDIS: "<<flag - (X+Length)<<endl;
    // cout<<"nextDIS: "<<(X+Length)<<endl;
    struct nextVehicleParams params;
    params.index = nextIndex;
    if (flag != -1){params.distance = flag - (X+Length);}
    else{params.distance = roadd[0].size() + 10;}
    
    return params;
}

void Vehicle::update(vector<vector<int>> roadd, vector<Vehicle> VehicleList,int RoadSignal, string RoadSignalState){
    struct nextVehicleParams nextps = nearestVehicle(roadd);
    int nextVehicle = nextps.index;
    int nextDistance = nextps.distance;
    
    // cout<<"next vehicle: "<<nextVehicle<<endl;
    int a = nextSpeedState(nextVehicle, nextDistance, VehicleList);
    
    VX = max(0, min(MaxSpeed, VX + a));

    // switch (nextSpeedState()){
    //     case 1:
    //         VX = max(0, min(MaxSpeed, VX + Max_Acceleration));      //clamp values to 0 and MaxSpeed
    //         break;
    //     case -1:
    //         VX = max(0, min(MaxSpeed, VX - Max_Acceleration));      //clamp values to 0 and MaxSpeed
    //         break;
    //     case 0:

    //         break;
    //     default:  ;
    // }
    X = X + VX;
}

void Vehicle::printParameters(){
  
    cout/*<<"Vehicle_Type: "*/<<this->Type<<endl;
    cout<<"    "<<"Vehicle_Length: "<<this->Length<<endl;
    cout<<"    "<<"Vehicle_Width: "<<this->Width<<endl;
    cout<<"    "<<"Vehicle_MaxSpeed: "<<this->MaxSpeed<<endl;
    cout<<"    "<<"Vehicle_Max_Acceleration: "<<this->Max_Acceleration<<endl;
}

bool Vehicle::isCrashed(){

    return false;
}

// void Vehicle::setX(int x, vector<vector<int>> roadd){

// }

// int main(){

//     Vehicle car1("Car", 5, 2, 5, 3);
//     Vehicle car2;
//     car1.printParameters();
//     car2.printParameters();
//     cout<< car2.X<<endl;
//     return 0;
// }