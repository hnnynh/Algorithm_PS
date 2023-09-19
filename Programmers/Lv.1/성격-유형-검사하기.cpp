#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "    ";
    bool used[4] = {false, };
    map<char, int> m;
    m['R'] = 0;     m['T'] = 0;     m['C'] = 0;     m['F'] = 0;
    m['J'] = 0;     m['M'] = 0;     m['A'] = 0;     m['N'] = 0;
    
    for(int i=0; i<survey.size(); i++){
        if(choices[i] - 4 < 0) 
            m[survey[i][0]] += 4 - choices[i];
        else if(choices[i] - 4 > 0)
            m[survey[i][1]] += choices[i] - 4;
    }
    vector<pair<char, int>> result (m.begin(), m.end());
    
    sort(result.begin(), result.end(), cmp);
    for(int i=0; i<result.size(); i++){
        if(result[i].first == 'R' || result[i].first == 'T'){
            if(used[0])
                continue;
            else{
                answer[0] = result[i].first;
                used[0] = true;
            }      
        }
        else if(result[i].first == 'C' || result[i].first == 'F'){
            if(used[1])
                continue;
            else{
                answer[1] = result[i].first;
                used[1] = true;;
            }      
        }
        else if(result[i].first == 'J' || result[i].first == 'M'){
            if(used[2])
                continue;
            else{
                answer[2] = result[i].first;
                used[2] = true;;
            }      
        }
        else if(result[i].first == 'A' || result[i].first == 'N'){
            if(used[3])
                continue;
            else{
                answer[3] = result[i].first;
                used[3] = true;;
            }      
        }
    }
    
    return answer;
}