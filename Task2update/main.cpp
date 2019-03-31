#include<iostream>
#include "Vehicle.h"
#include "Road.h"

using namespace std;

int main(){
    int t=1;
    // Vehicle car1("Car", 2, 2, 1, 1);
    // Vehicle car2;
    Road r(150,5,75,1);
    cout<<"Start\n";
    // r.render();
    // cout<<"Render complete\n";
    // r.update();
    // cout<<"Flush complete\n";
    // r.render();
    // cout<<"Done\n";
    r.addVehicle("Car", 2, 2, 5, 2);
    r.incrementTime();
    r.addVehicle("Truck", 3, 2, 3, 1);
    r.incrementTime();
    r.addVehicle("Car", 2, 2, 5, 2);
    r.incrementTime();
    r.addVehicle("bike", 2, 1, 5, 2);


    // r.VehicleList[0].X = 15;
    // r.VehicleList[1].X = 10;
    // r.VehicleList[2].X = 5;
    // r.VehicleList[3].X = 1;
    // r.VehicleList[1].Y = 2;
    // r.VehicleList[3].Y = 3;
    r.flush();
    r.renderVehicles();


    r.printVehicles();
    // car1.X = 5;
    cout<<"Position set\n";
    r.render();
    // r.VehicleList.push_back(car1);
    // cout<<"Vehicle pushed\n";
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;


    
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    // r.SignalState = "GREEN";
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.incrementTime();cout<<"t = "<<t++<<endl;
    r.SignalState = "GREEN";
    r.incrementTime();cout<<"t = "<<t++<<endl;r.incrementTime();cout<<"t = "<<t++<<endl;r.incrementTime();cout<<"t = "<<t++<<endl;r.incrementTime();cout<<"t = "<<t++<<endl;r.incrementTime();cout<<"t = "<<t++<<endl;r.incrementTime();cout<<"t = "<<t++<<endl;r.incrementTime();cout<<"t = "<<t++<<endl;r.incrementTime();cout<<"t = "<<t++<<endl;r.incrementTime();cout<<"t = "<<t++<<endl;r.incrementTime();cout<<"t = "<<t++<<endl;
    cout<<"Done\n";
    return 0;
}
