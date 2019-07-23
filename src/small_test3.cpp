#include <iostream>
#include<fstream>
#include <vector>
#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <chrono>

using namespace std;
using namespace rapidjson;
int main(int argc,char* argv[])
{
     auto start = chrono::steady_clock::now();
    
    if(argc==1)
        cout<<"Enter the file name to proceed";
    else
    {   
        vector<float> id1;
        vector<float> id2;
        FILE* fp = fopen(argv[1], "rb"); // non-Windows use "r"

        char readBuffer[65536];
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));

        Document d;
        d.ParseStream(is);
        fclose(fp);
        // StringBuffer buffer;
        //     Writer<StringBuffer> writer(buffer);
        //     d[0]["id"].Accept(writer);
        //     // Output {"project":"rapidjson","stars":11}
        //     std::cout << buffer.GetString() << std::endl<< std::endl<< std::endl<< std::endl;
        //     return 0;
        rapidjson::Value& a = d[0]["id"]; 
        // std::cout<<a.GetInt();
        // std::cout<<d.IsArray(); // attributes is an array
        // std::cout<<d.Size(); // attributes is an array
        int size = d.Size();

        float total_cost = 0;
        float max_max = 0;
        for(int pp=0;pp<size;pp++)
        {
            rapidjson::Value& r_id = d[pp]["id"];
            int id = r_id.GetInt();
            rapidjson::Value& c_id = d[pp]["cost"];
            float cost = c_id.GetFloat();
            total_cost = total_cost + cost;
            float max_cost_comp = 0;
            rapidjson::Value& cc = d[pp]["cost_components"];
            for (Value::ConstValueIterator itr = cc.Begin(); itr != cc.End(); ++itr)
            {  float val = itr->GetFloat();
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
     
