#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Vehicle.h"
#include "Road.h"


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
int main()
{
vector<string> s;
vector<struct VehicleParameter> vehicleData;
vector<struct RoadParameter>roadData;
s=getInput("parameters.ini");
int t=0;
string currentString;
vector<Road> roads;
Road r;
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
            struct RoadParameter temp;
            temp.Length = atoi( words[1].c_str() );
            temp.Width = atoi( words[2].c_str() );
            temp.Signal = atoi( words[3].c_str() );
            temp.ID = atoi( words[4].c_str() );

            roads.emplace_back(atoi( words[2].c_str() ), atoi( words[3].c_str() ), atoi( words[4].c_str() ), atoi( words[5].c_str() ));
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
            // cout<<"first if"<<endl;
            if(words[1] == "Pass"){
                int time = atoi(words[2].c_str());
                for (int i=0;i<time;i++){
                    // updateRoads(roads);
                roads[0].update();
                roads[0].render();
                }
            }else if(words[1] == "Signal"){
                // signalRoads(roads, words[2]); 
                
                roads[0].SignalState = words[2];
            // cout<<"second if "<<words[0]<<" "<<words[1]<<" "<<words[2]<<" "<<endl;
                roads[0].update();
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
                
                roads[0].update();
                roads[0].render();
            }
            cout<<"t = "<<t<<endl;
        }

        // roads[0].render();
  }


  
  
  
  
  
  return 0;



}