#include <iostream>
#include<fstream>
#include <vector>
#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <chrono>
#include <bits/stdc++.h> 
using namespace std; 
using namespace rapidjson;


class MyHashFunction1{ 
public: 

	// Use sum of lengths of first and last names 
	// as hash function. 
	size_t operator()(float p) const
	{ 	int q = p/10;
		// cout<<q<<"\n";
		return q; 
	} 
}; 


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
        rapidjson::Value& a = d[0]["id"]; 
        // std::cout<<a.GetInt();
        // std::cout<<d.IsArray(); // attributes is an array
        // std::cout<<d.Size(); // attributes is an array
        int size = d.Size();

	    unordered_map<float, int, MyHashFunction1> costaa;
    	unordered_map<int, multiset <float, greater <float> >> costaa2;



        for(int pp=0;pp<size;pp++)
        {
            rapidjson::Value& r_id = d[pp]["id"];
            int id = r_id.GetInt();
            rapidjson::Value& c_id = d[pp]["cost"];
            float cost = c_id.GetFloat();
            rapidjson::Value& cc = d[pp]["cost_components"];
            multiset <float, greater <float> > ccwot;         
            for (Value::ConstValueIterator itr = cc.Begin(); itr != cc.End(); ++itr)
                { float val = itr->GetFloat();
                         ccwot.insert(val);    
                        }
            costaa[cost] = id;
            costaa2[id] = ccwot;
        }

        float total_cost = 0;
        float max_max = 0;
        for (auto it = costaa.begin(); it != costaa.end(); it++ )
            {total_cost = total_cost + it->first;
                if(it->first >95)
                    id1.push_back(it->second);
            }
        for (auto it = costaa2.begin(); it != costaa2.end(); it++ )
            {   float a;
                a = *(it->second.begin());
                if(a>50)
                    id2.push_back(it->first);
                if(a>max_max)
                    max_max = a;
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
     
