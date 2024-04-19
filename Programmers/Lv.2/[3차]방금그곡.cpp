#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second < b.second;         // 순서 - 올림차순
    return a.first > b.first;               // 시간 - 내림차순
}

string solution(string m, vector<string> musicinfos) {
    vector<pair<int, int>> list;        // 시간, 입력 순서
    vector<string> name;
    
    m = regex_replace(m, regex("C#"), "c");
    m = regex_replace(m, regex("D#"), "d");
    m = regex_replace(m, regex("E#"), "e");
    m = regex_replace(m, regex("F#"), "f");
    m = regex_replace(m, regex("G#"), "g");
    m = regex_replace(m, regex("A#"), "a");
    m = regex_replace(m, regex("B#"), "b");
    
    for(int i=0; i<musicinfos.size(); i++){
        vector<string> split;
        string str, music = "";
        int idx = 0;
        istringstream ss(musicinfos[i]);
        while(getline(ss, str, ',')){
            split.push_back(str);
        }
        name.push_back(split[2]);
        
        int h1 = stoi(split[0].substr(0, 2)); 
        int m1 = stoi(split[0].substr(3, 2));
        int h2 = stoi(split[1].substr(0, 2));
        int m2 = stoi(split[1].substr(3, 2));
        int time = (h2-h1)*60+m2-m1;
        
        split[3] = regex_replace(split[3], regex("C#"), "c");
        split[3] = regex_replace(split[3], regex("D#"), "d");
        split[3] = regex_replace(split[3], regex("E#"), "e");
        split[3] = regex_replace(split[3], regex("F#"), "f");
        split[3] = regex_replace(split[3], regex("G#"), "g");
        split[3] = regex_replace(split[3], regex("A#"), "a");
        split[3] = regex_replace(split[3], regex("B#"), "b");
        
        for(int i=0; i<time; i++){
            if(idx == split[3].size())
                idx = 0;
            music += split[3][idx];
            idx++;
        }
        
        if (music.find(m) != string::npos) {
	        list.push_back({(h2-h1)*60+m2-m1, i});
        }
    }
    
    if(list.empty())
        return "(None)";
    
    sort(list.begin(), list.end(), cmp);
    
    return name[list[0].second];
}
