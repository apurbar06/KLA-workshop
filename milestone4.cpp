#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Pattern
{
public:
    int layer;
    int vertex_num;
    vector<pair<int, int>> vertex;
    vector<int> sides;
};

int main()
{
    ifstream POI_file("POI.txt");
    ifstream Source_file("Source.txt");
    ofstream out_file("output.txt");
    string str;
    Pattern obj1_POI, obj2_POI;
    int count = 0;

    while (getline(POI_file, str))
    {
        if (str=="boundary" and count==0)
        {
            count++;
            // cout << str << endl;
            // out_file<<str<< endl;
            for (int i = 0; i < 4; i++)
            {
                getline(POI_file, str);
                // cout<<str;
                // out_file<<str;
                istringstream ss(str);
                string word;
                vector<string> words;

                while (ss >> word)
                {
                    words.push_back(word);
                    // cout << word;
                }
                if(i==0) {
                    obj1_POI.layer = stoi(words[1]);
                } else if(i==2) {
                    obj1_POI.vertex_num = stoi(words[1]);
                    int idx=2;
                    for(int j=0; j<obj1_POI.vertex_num; j++) {
                        obj1_POI.vertex.push_back({stoi(words[idx]), stoi(words[idx+1])});
                        idx+=2;
                    }
                    for(int j=1; j<obj1_POI.vertex.size(); j++) {
                        // float angle = atan2(obj_POI.vertex[j].second - obj_POI.vertex[j-1].second, obj_POI.vertex[j].first - obj_POI.vertex[j-1].first);
                        int x2 = obj1_POI.vertex[j].first;
                        int x1 = obj1_POI.vertex[j-1].first;
                        int y2 = obj1_POI.vertex[j].second;
                        int y1 = obj1_POI.vertex[j-1].second;
                        int side = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
                        obj1_POI.sides.push_back(side);
                    }
                    // for(int j=0; j<obj1_POI.sides.size(); j++)
                    //     cout<< obj1_POI.sides[j]<<" ";
                    // cout<<endl<<endl;
                }
                // cout << endl;
                // out_file<<endl;
            }
            
        } else if(str=="boundary" and count==1) {
            for (int i = 0; i < 4; i++)
            {
                getline(POI_file, str);
                // cout<<str;
                // out_file<<str;
                istringstream ss(str);
                string word;
                vector<string> words;

                while (ss >> word)
                {
                    words.push_back(word);
                    // cout << word;
                }
                if(i==0) {
                    obj2_POI.layer = stoi(words[1]);
                } else if(i==2) {
                    obj2_POI.vertex_num = stoi(words[1]);
                    int idx=2;
                    for(int j=0; j<obj2_POI.vertex_num; j++) {
                        obj2_POI.vertex.push_back({stoi(words[idx]), stoi(words[idx+1])});
                        idx+=2;
                    }
                    for(int j=1; j<obj2_POI.vertex.size(); j++) {
                        // float angle = atan2(obj_POI.vertex[j].second - obj_POI.vertex[j-1].second, obj_POI.vertex[j].first - obj_POI.vertex[j-1].first);
                        int x2 = obj2_POI.vertex[j].first;
                        int x1 = obj2_POI.vertex[j-1].first;
                        int y2 = obj2_POI.vertex[j].second;
                        int y1 = obj2_POI.vertex[j-1].second;
                        int side = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
                        obj2_POI.sides.push_back(side);
                    }
                    for(int j=0; j<obj2_POI.sides.size(); j++)
                        cout<< obj2_POI.sides[j]<<" ";
                    cout<<endl<<endl;
                }
                // cout << endl;
                // out_file<<endl;
            }
            break;
        }

    }

    // cout<<obj_POI.layer<<endl;
    // cout<<obj_POI.vertex_num<<endl;
    // for(auto e:obj_POI.vertex)
    //     cout<<e.first<<","<<e.second<<"  ";
    // cout<<endl;





    count = 0;
    Pattern obj1_Source, obj2_Source;
    while (getline(Source_file, str))
    {
        
        if (str=="boundary")
        {
            count++;
            // cout << str << endl;
            // out_file<<str<< endl;
            string outStr = "";
            outStr += str+"\n";
            for (int i = 0; i < 4; i++)
            {
                getline(Source_file, str);
                // cout<<str;
                // out_file<<str;
                outStr += str+"\n";
                istringstream ss(str);
                string word;
                vector<string> words;

                while (ss >> word)
                {
                    words.push_back(word);
                    // cout << word;
                }
                if(i==0) {
                    obj2_Source.layer = stoi(words[1]);
                } else if(i==2) {
                    obj2_Source.vertex_num = stoi(words[1]);

                    int idx=2;
                    for(int j=0; j<obj2_Source.vertex_num; j++) {
                            obj2_Source.vertex.push_back({stoi(words[idx]), stoi(words[idx+1])});
                            idx+=2;
                    }
                        
                    for(int j=1; j<obj2_Source.vertex.size(); j++) {
                            int x2 = obj2_Source.vertex[j].first;
                            int x1 = obj2_Source.vertex[j-1].first;
                            int y2 = obj2_Source.vertex[j].second;
                            int y1 = obj2_Source.vertex[j-1].second;
                            int side = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
                            obj2_Source.sides.push_back(side);
                    }

                    if(count<=1) {
                        obj1_Source.layer = obj2_Source.layer;
                        obj1_Source.vertex_num = obj2_Source.vertex_num;
                        obj1_Source.vertex = obj2_Source.vertex;
                        obj1_Source.sides = obj2_Source.sides;
                    } else {
                        // cout<<count<<endl;
                        if((obj1_Source.vertex_num == obj1_POI.vertex_num) and (obj2_Source.vertex_num == obj2_POI.vertex_num)) {
                            cout<<obj1_Source.vertex_num<<","<<obj1_POI.vertex_num<<"  "<<obj2_Source.vertex_num<<","<<obj2_POI.vertex_num<<endl;
                            // bool isSame = true;
                            
                            
                            // for(int j=0; j<obj_Source.vertex_num; j++) {
                            //     // obj_Source.vertex.push_back({stoi(words[idx]), stoi(words[idx+1])});
                            //     if((obj_POI.vertex[idx-2].first != stoi(words[idx]))  or  (obj_POI.vertex[idx-2+1].second != stoi(words[idx+1]))) {
                            //         isSame = false;
                            //         break;
                            //     }
                            //     idx+=2;
                            // } 

                            if((obj1_POI.sides == obj1_Source.sides) and (obj2_POI.sides == obj2_Source.sides)) {
                                outStr += "endel\n";
                                cout<<outStr;
                                out_file<<outStr;
                                 
                            }

                            // for(int j=0; j<=obj_Source.sides.size(); j++) {
                                
                            //     int front = obj_Source.sides[0];
                            //     obj_Source.sides.erase(obj_Source.sides.begin());
                            //     obj_Source.sides.push_back(front);
                            // }
                                
                        }
                        obj1_Source.layer = obj2_Source.layer;
                        obj1_Source.vertex_num = obj2_Source.vertex_num;
                        obj1_Source.vertex = obj2_Source.vertex;
                        obj1_Source.sides = obj2_Source.sides;
                    }
                    
                    
                }
                
            }
            // cout<<outStr;
            // out_file<<outStr;
        }
        else {
            cout << str << endl;
            out_file<<str<< endl;
        }

    }

    return 0;
}