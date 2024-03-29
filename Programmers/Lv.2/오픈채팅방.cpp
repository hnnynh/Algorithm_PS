#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<pair<int, string>> answer;
    vector<string> result;
    map<string, string> m;
    
    for(auto r:record){
        string com, id, name;
        stringstream ss(r);
        ss >> com >> id >> name;
        
        if(com == "Enter"){         // 1
            answer.push_back({1, id});
            m[id] = name;
        }
        else if(com == "Leave"){    // -1
            answer.push_back({-1, id});
        }
        else if(com == "Change"){
            m[id] = name;
        }
    }
    
    for(auto a:answer){
        if(a.first == 1)
            result.push_back(m[a.second] + "님이 들어왔습니다.");
        else
            result.push_back(m[a.second] + "님이 나갔습니다.");
    }
    
    return result;
}
