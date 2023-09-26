#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<int> v;
    map<string, int> dict;
    string temp = "", prev;
    int idx = 1;
    
    dict[""] = 0;
    for(int i=0; i<26; i++){
        temp = "";
        temp += 'A' + i;
        dict[temp] = idx++;
    }
    
    temp = ""; 
    for(int i=0; i<msg.length(); i++){
        prev = "";
        for(int j=i; j<=msg.length(); j++){
            temp += msg[j];
            if(dict.find(temp) != dict.end()){
                prev = temp;
            }
            else{
                cout << j << " " << prev << " " << temp << endl;
                i += prev.length() - 1;
                answer.push_back(dict[prev]);
                dict[temp] = idx++;
                prev = temp;
                temp = "";
                break;
            }
        }
    }
    
    
    return answer;
}