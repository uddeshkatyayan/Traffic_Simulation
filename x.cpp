#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main(){

    string s = "Hello there!";

    vector<string> result;
istringstream iss(s);
for(string s; iss >> s; )
    result.push_back(s);
    cout<<result[0]<<endl;
    cout<<result[1]<<endl;

    return 0;
}