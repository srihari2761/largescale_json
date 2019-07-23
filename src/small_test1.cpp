#include <iostream>
#include<fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;
int main()
{
    

    std::ifstream i("small.json");
    json j;
    i >> j;
    json cc = j["cost_components"];
    cout<<"\n Size is "<<cc.size()<<endl;
    int sum = 0;
    int count = cc.size();
    int max = 0;
    for (auto it = cc.begin(); it != cc.end(); ++it)
    {
        std::cout << it.value()<< std::endl;
        sum = sum+ it.value();
        int value;
        value = it.value();
        if(value>max)
        {
            max = value;
        }

    }
    float average = sum/count;
    

    }