#include <iostream>

using namespace std;

class Road
{
public:
  int Road_Id;
  int Road_Length;
  int Road_Width;
  int Road_Signal;

  void Road(int id, int len, int wid, int sig)
  {
    Road_Id=id;
    Road_Length=len;
    Road_Width=wid;
    Road_Signal=sig;
  }
};

class Vehicle
{
  public:
    int MaxSpeed;
    int Accleration;
    int Vehicle_Length;
    int Vehicle_Width;
    string Vehicle_Type;

    void Vehicle(string type, int len, int wid)
    {
      Vehicle_Type=type;
      Vehicle_Length=len;
      Vehicle_Width=wid;
    }

    void Vehicle(string type, int len, int wid, int max, int acc)
    {
      Vehicle_Type=type;
      Vehicle_Length=len;
      Vehicle_Width=wid;
      MaxSpeed=max;
      Accleration=acc;
    }

    // int setMaxSpeed(int max)
    // {
    //   MaxSpeed=max;
    // }
    //

}
