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
    vector<vector<int> > temp2(Road_Width+2, vector<int>(Road_Length, -1));
    this->road = temp;
    this->roadd = temp2;
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

    for(int i=1; i<=this->Width; i++){
        for(int j=0; j<this->roadd[0].size(); j++){
        this->roadd[i][j] = -1;
        }
    }
    for(int j=0; j<this->roadd[0].size(); j++){
        this->roadd[0][j] = -3;
    }
    for(int j=0; j<this->roadd[0].size(); j++){
        this->roadd[road.size()-1][j] = -3;
    }
    if(this->SignalState == "RED"){
        for(int i=1; i<=this->Width; i++){
            this->roadd[i][this->Signal] = -2;
        }
    }

}

//first reset the road (flush), then update each vehicle (its parameters and statuses),
//and finally place each vehicle back on the road
void Road::update(){
    vector<vector<char>> temp(road);
    // flush(&temp);
    
    // cout<< "works!" <<endl;
    
    //later try to update within the other loop itself and observe differences
    for (int i=0; i<VehicleList.size(); i++){
        VehicleList[i].update(roadd, VehicleList, Signal, SignalState);
    }

    flush();


    for (int i=0; i<VehicleList.size(); i++){
        for(int j=VehicleList[i].X; j<VehicleList[i].X + VehicleList[i].Length; j++){
            for(int k=VehicleList[i].Y; k<VehicleList[i].Y + VehicleList[i].Width; k++){
                if( j<road[0].size() ) road[k][j] = VehicleList[i].Type[0];
            }
        }
    }

    for (int i=0; i<VehicleList.size(); i++){
        for(int j=VehicleList[i].X; j<VehicleList[i].X + VehicleList[i].Length; j++){
            for(int k=VehicleList[i].Y; k<VehicleList[i].Y + VehicleList[i].Width; k++){
                if( j<road[0].size() ) roadd[k][j] = i;
            }
        }
    }
    // this->road = temp;
}

void Road::render(){
    // for(int i=0; i<this->road.size(); i++){
    //     for(int j=0; j<this->road[0].size(); j++){
    //         cout<<this->road[i][j];
    //     }
    //     cout<<endl;
    // }

    for(int i=0; i<this->roadd.size(); i++){
        for(int j=0; j<this->roadd[0].size(); j++){
            if (roadd[i][j] >=0) {
                cout<<this->VehicleList[ roadd[i][j] ].Type[0];
            }else {
                if (i==0 || i == roadd.size()-1 ){
                    cout<<'-';
                }else {
                    if (roadd[i][j] == -2)
                        {cout<<'|';}
                    else{
                        cout<<' ';
                    }
                }
            }

            // cout<<roadd[i][j];
        }
        cout<<endl;
    }
}

void Road::addVehicle(string Vehicle_Type, int Vehicle_Length, int Vehicle_Width, int Vehicle_MaxSpeed, int Vehicle_Max_Acceleration){
    // Vehicle temp(string Vehicle_Type, int Vehicle_Length, int Vehicle_Width, int Vehicle_MaxSpeed, int Vehicle_Max_Acceleration);
    // VehicleList.emplace_back(temp);
    VehicleList.emplace_back(Vehicle_Type, Vehicle_Length, Vehicle_Width, Vehicle_MaxSpeed, Vehicle_Max_Acceleration);
    Vehicle last = VehicleList[ VehicleList.size()-1 ];
    
    cout<<VehicleList.size()-1<<" "<< last.X <<" "<<last.Y<<endl;
    printVehicles();
    int startingY = 1;
    int flag = 0;
    for (int i=1; i<=Width-Vehicle_Width +1; i++){
        
        flag = 1;
        for(int j=0;j<Vehicle_Width;j++){
            if (roadd[startingY+j][0] != -1) {flag = 0;};
        }
        if (flag == 1) {break;}
        startingY++;
    }
    cout<<startingY<<endl;
    if (startingY <= Width-Vehicle_Width +1){
        VehicleList[ VehicleList.size()-1 ].Y = startingY;
    }
    for(int i = last.X ; i < last.X + last.Length; i++)
    {
        for(int j = last.Y; j < last.Y + last.Width; j++)
        {
            if( (i>-1) && (j>-1) && (i<this->Length) && (j<this->Width )){
                this->roadd[j][i] = VehicleList.size()-1;
                this->road[j][i] = Vehicle_Type[0];
            }
        }
        
    }
}

void Road::incrementTime(){
    this->update();
    this->render();
}

void Road::printVehicles(){
    for(int i=0; i<this->VehicleList.size(); i++){
        cout<<i<<". Type: "<<this->VehicleList[i].Type<<"\t Id: "<<this->VehicleList[i].Id<<"\t X: "<<this->VehicleList[i].X<<"\t Y: "<<this->VehicleList[i].Y<<endl;
    }
}

void Road::renderVehicles(){
    for (int i=0; i<VehicleList.size(); i++){
        for(int j=VehicleList[i].X; j<VehicleList[i].X + VehicleList[i].Length; j++){
            for(int k=VehicleList[i].Y; k<VehicleList[i].Y + VehicleList[i].Width; k++){
                if( j<road[0].size() ) road[k][j] = VehicleList[i].Type[0];
            }
        }
    }

    for (int i=0; i<VehicleList.size(); i++){
        for(int j=VehicleList[i].X; j<VehicleList[i].X + VehicleList[i].Length; j++){
            for(int k=VehicleList[i].Y; k<VehicleList[i].Y + VehicleList[i].Width; k++){
                if( j<road[0].size() ) roadd[k][j] = i;
            }
        }
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
