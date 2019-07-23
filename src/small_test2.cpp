#include <iostream>
#include<fstream>
#include <nlohmann/json.hpp>
#include <chrono>
using json = nlohmann::json;
using namespace std;
int main(int argc,char* argv[])
{   
    auto start = chrono::steady_clock::now();
    
    if(argc==1)
        cout<<"Enter the file name to proceed";
    else
    {   
        vector<float> id1;
        vector<float> id2;
        float total_cost = 0;
        float max_max = 0;
        std::ifstream i(argv[1]);
        json j;
        i >> j;
        // cout<<"ISARRAY   "<<j.is_array();
        // cout<<"\n Size is "<<j.size()<<endl;
        int size = j.size();
        for(int k=0;k<size;k++)
        {
            json temp = j[k];
            int id = temp["id"];
            float cost = temp["cost"];
            total_cost = total_cost + cost;
            float max_cost_comp = 0;
            for (auto it = temp["cost_components"].begin(); it != temp["cost_components"].end(); ++it)
            {
                float val = it.value();
                if(max_cost_comp<val)
                    max_cost_comp = val;
            }
            if(max_max < max_cost_comp)
            {
                max_max = max_cost_comp;
            }
            if(cost>95)
                id1.push_back(id); 
            if(max_cost_comp>50)
                id2.push_back(id);

        }

        total_cost = total_cost/size;
        cout<<"1: "<<total_cost<<endl;
        cout<<"2: "<<max_max<<endl;
        cout<<"3: ";
        for (auto pp = id1.begin(); pp != id1.end(); ++pp) 
            {cout << *pp;

            if(std::next(pp) != id1.end()) // last element
                    {
                        cout << ",";
                    }
                }
        cout<<endl;
        cout<<"4: ";
        for (auto pp = id2.begin(); pp != id2.end(); ++pp) 
            {cout << *pp;
            if(std::next(pp) != id2.end()) // last element
                {
                    cout << ",";
                }}
        cout<<endl;

    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
}