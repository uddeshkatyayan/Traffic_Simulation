#include<iostream>
#include "Vehicle.h"
#include "Road.h"

using namespace std;

int main(){
    int t=1;
    Vehicle car1("Car", 2, 2, 1, 1);
    Vehicle car2;
    Road r(30,5,15,1);
    cout<<"Start\n";
    // r.render();
    // cout<<"Render complete\n";
    // r.update();
    // cout<<"Flush complete\n";
    // r.render();
    // cout<<"Done\n";
    

    
    car1.X = 5;
    cout<<"Position set\n";
    r.VehicleList.push_back(car1);
    cout<<"Vehicle pushed\n";
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.SignalState = "GREEN";
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    r.update();
    r.render();cout<<"t = "<<t++<<endl;
    cout<<"Done\n";
    return 0;
}
