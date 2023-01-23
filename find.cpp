#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Pattern
{
public:
    int layer;
    int vertex_num;
    vector<pair<int, int>> vertex;
};

int main()
{
    ifstream file("Format_Source.txt");
    ofstream out_file("output.txt");
    string str;
    Pattern obj;
    int count = 0;

    while (getline(file, str))
    {
        if (str=="boundary" && count<2)
        {
            count++;
            cout << str << endl;
            out_file<<str<< endl;
            for (int i = 0; i < 4; i++)
            {
                getline(file, str);
                cout<<str;
                out_file<<str;
                istringstream ss(str);
                string word;
                vector<string> words;

                while (ss >> word)
                {
                    words.push_back(word);
                    // cout << word;
                }
                if(i==0) {
                    obj.layer = stoi(words[1]);
                } else if(i==2) {
                    obj.vertex_num = stoi(words[1]);
                    int idx=2;
                    for(int j=0; j<obj.vertex_num; j++) {
                        obj.vertex.push_back({stoi(words[idx]), stoi(words[idx+1])});
                        idx+=2;
                    }
                }
                cout << endl;
                out_file<<endl;
            }
        }
        else if (str=="boundary" && count>=2)
        {
            for(int i=0; i<4; i++)
                getline(file, str);
            
        } else {
            cout << str << endl;
            out_file<<str<< endl;
        }
    }

    return 0;
}