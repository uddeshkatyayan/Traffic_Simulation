#include <iostream>
#include <vector>

using namespace std;

class Vehicle
{
  public:
    int MaxSpeed;
    int Accleration;
    int Vehicle_Length;
    int Vehicle_Width;
    string Vehicle_Type;
    string color;
    int timeEntry;
    char** rep;

    Vehicle(string type, string color, int len, int wid, int t)
    {
      Vehicle_Type=type;
      Vehicle_Length=len;
      Vehicle_Width=wid;
      MaxSpeed=1;
      Accleration=1;
      timeEntry=t;
      this->rep=new char*[len];
      for(int i=0;i<len;i++)
      {
        this->rep[i]=new char[wid];
      }
      char R='';
      if(type="car")
        R='C';
      else if(type="bus")
        R='B';
      else if(type="truck")
        R='T';
      else if(type="bike")
        R='b';
      else;
      for(int i=0; i<len; i++)
      {
        for(int j=0; j< wid; j++)
          rep[i][j]=R;
      }
    }

    Vehicle(string type, string color, int len, int wid, int max, int acc, int t)
    {
      Vehicle_Type=type;
      Vehicle_Length=len;
      Vehicle_Width=wid;
      MaxSpeed=max;
      Accleration=acc;
      timeEntry=t;

    }

    // int setMaxSpeed(int max)
    // {
    //   MaxSpeed=max;
    // }
    //
};

class Road
{
public:
  int Road_Id;
  int Road_Length;
  int Road_Width;
  int Road_Signal;
  vector<Vehicle> Vehicles;
  char** conf;

  Road(int id, int len, int wid, int sig, vector<Vehicle> v)
  {
    this->Road_Id=id;
    this->Road_Length=len;
    this->Road_Width=wid;
    this->Road_Signal=sig;
    this->Vehicles=v;
    this->conf=new char*[Road_Length];
    for(int i=0;i<Road_Length;i++)
    {
      this->conf[i]=new char[Road_Width];
    }
    for(int i=0;i<Road_Length;i++)
    {
      this->conf[i][0]='-';
      this->conf[i][Road_Width-1]='-';
    }
  }

  void printSim()
  {
    for (int i = 0; i < this->Road_Width; i++) {
                   for (int j = 0; j < this->Road_Length; j++)
                       cout << this->conf[j][i];
                   cout << endl;
                }
  }

  void Update_step()
  {

  }
};



int main()
{
  Vehicle v1("car",2,2,1);
  Vehicle v2("bus",3,2,2);
  Vehicle v3("bike",2,1,3);
  vector<Vehicle> vh;
  vh.push_back(v1);
  vh.push_back(v2);
  vh.push_back(v3);
  Road rd(1,30,10,15,vh);
  rd.printSim();
  return 0;
}
