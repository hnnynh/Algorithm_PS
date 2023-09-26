#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> store;
    map<int, bool> m;
    
    for(int i=1; i<s.length(); i++){
        if(s[i] == '{'){
            vector<int> v; 
            i++;
            string temp = "";
            while(s[i] != '}'){
                if('0' <= s[i] && s[i] <= '9'){
                    temp += s[i];
                }
                else if(s[i] == ','){
                    v.push_back(stoi(temp));
                    m[stoi(temp)] = false;
                    temp = "";   
                }
                i++;   
            }
            m[stoi(temp)] = false;
            v.push_back(stoi(temp));
            store.push_back(v);
        } 
    }
    
    sort(store.begin(), store.end(), cmp);
    
    for(int i=0; i<store.size(); i++){
        for(int j=0; j<store[i].size(); j++){
            if(!m[store[i][j]]){
                answer.push_back(store[i][j]);
                    m[store[i][j]] = true;
            break;
            }
        }
    }
    
    return answer;
}