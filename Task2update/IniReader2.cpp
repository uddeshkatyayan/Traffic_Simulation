#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Vehicle.h"
#include "Road.h"
#include<GL/glut.h>

using namespace std;

struct RoadParameter
{
   int Length;
   int Width;
   int Signal;
   int ID;
};



struct VehicleParameter
{
   string Type;
   int Length;
   int Width;
   int Max_Speed;
   int Max_Acceleration;
};


int x, y;
float i, j;
int n_len=40;
int n_wid=25;

int xfac = 40;
int yfac = 100;
int padding = 10;

void myInit (int l, int w)
{
  // yfac=(xfac*768
  int wind_len=l*xfac;
  int wind_wid=(w+5)*yfac;
    // Reset background color with black (since all three argument is 0.0)
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set picture color to green (in RGB model)
    // as only argument corresponding to G (Green) is 1.0 and rest are 0.0
    glColor3f(0.0, 1.0, 0.0);

    // Set width of point to one unit
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set window size in X- and Y- direction
    gluOrtho2D(-wind_len/2, wind_len/2, -wind_wid/2, wind_wid/2);
}

void display(vector<float> k,int count,Road r)
// for (float k = -500; k < 421; k += 0.05)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);


  int car_len = 80;
  int bike_len= 80;
  int bike_wid= 25;
  int car_wid = 50;



    int road_len=r.Length*xfac;
    int road_wid=(r.Width+1)*yfac;
    int road_sig=(r.Signal)*xfac- road_len/2;


    //Loop is to draw the road
    glColor3f(1.0, 1.0, 1.0);
    int skip = 10;
    int jump = 0;
    for(i=-(road_len/2) ; i<road_len/2; i++)
    {
      // if(skip = 10)skip=0;
      x=i;
      glVertex2i(x,road_wid/2);
      glVertex2i(x,-road_wid/2);
    }

    for(i=-(road_len/2) ; i<road_len/2; i+=skip)
    {
      x=i;

      for(int j=0; j<= r.Width; j++){

        glVertex2i(x, road_wid/2 - (j + 0.5)*yfac);}

    }


    if(r.SignalState.compare("GREEN")==0)
      glColor3f(0.0, 1.0, 0.0);
    else
      glColor3f(1.0, 0.0, 0.0);
      //signal line
    for(i=-(road_wid/2); i<road_wid/2+1; i++)
    {
      y=i;
      glVertex2i(road_sig,y);
    }

//random lines
    // for(i=-(road_wid/2); i<road_wid/2+1; i++)
    // {
    //   y=i;
    //   glVertex2i(-540,y);
    // }
    //
    // for(i=-(road_wid/2); i<road_wid/2+1; i++)
    // {
    //   y=i;
    //   glVertex2i(-500,y);
    // }


    glColor3f(0.5, 0.1, 0.1);

      for(int m=0; m<count; m++ )
      {
       if(r.VehicleList[m].Colour=="RED")
        {  glColor3f(1, 0, 0);}
      else if(r.VehicleList[m].Colour.compare("GREEN")==0)
             glColor3f(0, 1, 0);
      else if(r.VehicleList[m].Colour.compare("BLUE")==0)
                glColor3f(0, 0, 1);
      else
                glColor3f(1,1,1);

                //horizontal line for cars
        for(i= k[m]+padding; i<(k[m]+(xfac*r.VehicleList[m].Length)-1-padding) ; i++)
        {
          x=i;
          // cout<<(n_wid*r.VehicleList[i].Width)<<endl;
          glVertex2i(x,((road_wid/2)-(r.VehicleList[m].Y-1)*(yfac)) -(yfac/2) -padding);
          glVertex2i(x,((road_wid/2)-(r.VehicleList[m].Y +r.VehicleList[m].Width -1)*(yfac) -(yfac/2))+padding);
        }

        //vertical line for cars
        for(i=((road_wid/2)-(r.VehicleList[m].Y +r.VehicleList[m].Width -1)*(yfac) -(yfac/2))+padding;  i<((road_wid/2)-(r.VehicleList[m].Y-1)*(yfac)) -(yfac/2) -padding; i++)
        {

          //cout<<i<<endl;

          y=i;
          glVertex2i(k[m]+padding,y);
          glVertex2i(k[m]-padding+(xfac * r.VehicleList[m].Length),y);
        }

    }
    glEnd();
    glFlush();
}


vector<string> getInput(string filename) {
  string line;
  vector<string> output;
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
    //   cout << line << '\n';
      if((line.compare(0,line.length(),""))!=0)
      output.push_back(line);

    }
    myfile.close();
  }
  else cout << "Unable to open file";
  return output;

}
void updateRoads(vector <Road> r){
    for(int i=0; i<r.size(); i++){
        r[i].update();
        r[i].render();
    }

}

void signalRoads(vector <Road> r, string colour){
    for(int i=0; i<r.size(); i++){
        r[i].SignalState = colour;
    }

}

void addVeh(vector <Road> r, string type, vector<struct VehicleParameter> vps, string colour){

    int vNum = -1;
    for(int i=0; i<vps.size(); i++){
        if(vps[i].Type == type){
            vNum = i;
        }
    }
    for(int i=0; i<r.size(); i++){
        // Vehicle v(type, vps[i].Length, vps[i].Width, vps[i].Max_Speed, vps[i].Max_Acceleration, colour);
        r[i].addVehicle(type, vps[vNum].Length, vps[vNum].Width, vps[vNum].Max_Speed, vps[vNum].Max_Acceleration, colour);
    }

}
int main(int argc, char** argv)
{


    glutInit(&argc, argv);

    // Display mode which is of RGB (Red Green Blue) type
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Declares window size
    glutInitWindowSize(1400, 500);

    // Declares window position which is (0, 0)
    // means lower left corner will indicate position (0, 0)
    glutInitWindowPosition(0, 0);

    // Name to window
    glutCreateWindow("Traffic Simulations");



vector<string> s;
vector<struct VehicleParameter> vehicleData;
vector<struct RoadParameter>roadData;
s=getInput("parameters1.ini");
int t=0;
string currentString;
vector<Road> roads;
Road r;
int xyFlag = 0;
//   r.render();
//   roads.push_back(r);

    // for (int i=0; i<s.size(); i++){
    // }

  for (int i=0; i<s.size(); i++){
        cout<<s[i]<<endl;
       vector<string> words;
    currentString = s[i];
    // cout<<currentString<<"rth"<<endl;
    istringstream iss(currentString);
    for(string currentString; iss >> currentString;){
        words.push_back(currentString);
    }
    // cout<<"finetillhere"<<endl;
    for (int j=0; j<words.size();j++){
        // cout<<words[j]<<"\t";

    }
    // cout<<"%%%"<<endl;

            // cout<<words[0]<<" words[0]"<<endl;

        if(words[0] == "[RoadParameters]"){
            // struct RoadParameter temp;
            // temp.Length = atoi( words[1].c_str() );
            // temp.Width = atoi( words[2].c_str() );
            // temp.Signal = atoi( words[3].c_str() );
            // temp.ID = atoi( words[4].c_str() );

            roads.emplace_back(atoi( words[2].c_str() ), atoi( words[3].c_str() ), atoi( words[4].c_str() ), atoi( words[5].c_str() ));
// cout<< atoi( words[2].c_str() )<<endl;
            if(xyFlag==0)
            {
              // Call to myInit()
              myInit( atoi( words[2].c_str() ),  atoi( words[3].c_str() ));
              xyFlag++;
            }
            // cout<<roads.size()<<"sefef"<<endl;
            // roads[0].Length = atoi( words[1].c_str() );
            // roads[0].Width = atoi( words[2].c_str() );
            // roads[0].Signal = atoi( words[3].c_str() );
            // roads[0].Id = atoi( words[4].c_str() );

        }else if(words[0] == "[VehicleParameters]"){
            struct VehicleParameter temp;
            temp.Type =  words[1] ;
            temp.Length = atoi( words[2].c_str() );
            temp.Width = atoi( words[3].c_str() );
            temp.Max_Speed = atoi( words[4].c_str() );
            temp.Max_Acceleration = atoi( words[5].c_str() );
            vehicleData.push_back(temp);

            // roads[0].update();
            // roads[0].render();
            // updateRoads(roads);
        }else if(words[0] == "[Simulate]"){
            t++;
            vector<float> x(roads[0].VehicleList.size());
            vector<float> y(roads[0].VehicleList.size());
            for (int i=0; i<roads[0].VehicleList.size();i++){
              x[i] = -roads[0].Length*xfac/2 +xfac*roads[0].VehicleList[i].X;

              // y[i] = ;
            }
          // if  (roads[0].VehicleList.size()>=3 && xyFlag ==1){
          //   x[0]=-540;
          //
          //   x[1]=-500;
          //   x[2]=-340;
          //   xyFlag=0;
          // }

            // cout<<"first if"<<endl;
            if(words[1] == "Pass"){
                int time = atoi(words[2].c_str());
                for (int i=0;i<time;i++){
                    // updateRoads(roads);
                roads[0].update();

            if(roads[0].VehicleList.size()>0)  {
               for (int i=0; i<4000; i++)
                {
                  for(int k=0;k<roads[0].VehicleList.size();k++)
                  {

                      x[k]+=0.00025*roads[0].VehicleList[k].VX*xfac;

                    }
                 display(x,roads[0].VehicleList.size(),roads[0]);

                }
              }
                roads[0].render();
                cout<<"t = "<<t<<endl;
                t++;
                }
                t--;
            }else if(words[1] == "Signal"){
                // signalRoads(roads, words[2]);

                roads[0].SignalState = words[2];
            // cout<<"second if "<<words[0]<<" "<<words[1]<<" "<<words[2]<<" "<<endl;
                roads[0].update();

                if(roads[0].VehicleList.size()>0)  {
                  for (int i=0; i<4000; i++)
                    {
                      for(int k=0;k<roads[0].VehicleList.size();k++)
                      {

                          x[k]+=0.00025*roads[0].VehicleList[k].VX*xfac;

                        }
                     display(x,roads[0].VehicleList.size(),roads[0]);

                    }
                  }
                roads[0].render();
            }else{

                // cout << words[1]<<endl;
                // addVeh(roads, words[1], vehicleData, words[2]);
                int vNum = -1;
                for(int i=0; i<vehicleData.size(); i++){
                    // cout<<i<<" "<<vehicleData[i].Type<<endl;
                    if(vehicleData[i].Type == words[1]){
                        vNum = i;
                        break;
                    }
                }
                // for(int i=0; i<r.size(); i++){
                        //   //    Vehicle v(type, vps[i].Length, vps[i].Width, vps[i].Max_Speed, vps[i].Max_Acceleration, colour);
                    roads[0].addVehicle(words[1], vehicleData[vNum].Length, vehicleData[vNum].Width, vehicleData[vNum].Max_Speed, vehicleData[vNum].Max_Acceleration, words[2]);
                // }
                x.push_back(-roads[0].Length*xfac/2 +xfac*roads[0].VehicleList[ roads[0].VehicleList.size() -1 ].X); //check
                roads[0].update();



                // for(int i=0;i<roads[0].VehicleList.size();i++){
                //   x[i] += n_len*roads[0].VehicleList[i].VX;
                // }
                //
                if(roads[0].VehicleList.size()>0)  {



                    for (int i=0; i<4000; i++)
                    {
                     for(int k=0;k<roads[0].VehicleList.size();k++)
                      {
                        x[k]+=0.00025*roads[0].VehicleList[k].VX*xfac;
                      }
                     display(x,roads[0].VehicleList.size(),roads[0]);

                    }
                  }

                roads[0].render();
            }

            if(words[1] != "Pass"){cout<<"t = "<<t<<endl;}
        }

        // roads[0].render();
  }







  return 0;



}
