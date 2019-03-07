#include <iostream>
#include <string>
#include <vector>
#include "Road.h"
#include "Vehicle.h"

using namespace std;

Road::Road(){
    
}

Road::Road(int Road_Length, int Road_Width, int Road_Signal, int Road_Id){
    vector<vector<char> > temp(Road_Width+2, vector<char>(Road_Length, ' '));
    this->road = temp;
    this->Length = Road_Length;
    this->Width = Road_Width;
    this->Signal = Road_Signal;
    this->SignalState = "RED";
}

Road::~Road(){

}

void Road::flush(){
    for(int i=1; i<=this->Width; i++){
        for(int j=0; j<this->road[0].size(); j++){
        this->road[i][j] = ' ';
        }
    }
    for(int j=0; j<this->road[0].size(); j++){
        this->road[0][j] = '-';
    }
    for(int j=0; j<this->road[0].size(); j++){
        this->road[road.size()-1][j] = '-';
    }
    if(this->SignalState == "RED"){
        for(int i=1; i<=this->Width; i++){
            this->road[i][this->Signal] = '|';
        }
    }
}

//first reset the road (flush), then update each vehicle (its parameters and statuses),
//and finally place each vehicle back on the road
void Road::update(){
    flush();

    //later try to update within the other loop itself and observe differences
    for (int i=0; i<VehicleList.size(); i++){
        VehicleList[i].update(SignalState, Signal);
    }

    for (int i=0; i<VehicleList.size(); i++){
        for(int j=VehicleList[i].X; j<VehicleList[i].X + VehicleList[i].Length; j++){
            for(int k=VehicleList[i].Y; k<VehicleList[i].Y + VehicleList[i].Width; k++){
                if( j<road[0].size() ) road[k][j] = VehicleList[i].Type[0];
            }
        }
    }
}

void Road::render(){
    for(int i=0; i<this->road.size(); i++){
        for(int j=0; j<this->road[0].size(); j++){
            cout<<this->road[i][j];
        }
        cout<<endl;
    }
}

void Road::addVehicle(string Vehicle_Type, int Vehicle_Length, int Vehicle_Width, int Vehicle_MaxSpeed, int Vehicle_Acceleration){
    // Vehicle temp(string Vehicle_Type, int Vehicle_Length, int Vehicle_Width, int Vehicle_MaxSpeed, int Vehicle_Acceleration);
    // VehicleList.emplace_back(temp);
    VehicleList.emplace_back(Vehicle_Type, Vehicle_Length, Vehicle_Width, Vehicle_MaxSpeed, Vehicle_Acceleration);
}

void Road::incrementTime(){
    this->update();
    this->render();
}

void Road::printVehicles(){
    for(int i=0; i<this->VehicleList.size(); i++){
        cout<<i<<". Type: "<<this->VehicleList[i].Type<<"\t Id: "<<this->VehicleList[i].Id<<endl;
    }
}

// int main(){

//     Road r(30,5,15,1);
//     cout<<"Start\n";
//     r.render();
//     cout<<"Render complete\n";
//     r.flush();
//     cout<<"Flush complete\n";
//     r.render();
//     cout<<"Done\n";
//     Vehicle v1();
//     v1.X = 5;
//     r.VehicleList.push_back(v1);

//     return 0;
// }