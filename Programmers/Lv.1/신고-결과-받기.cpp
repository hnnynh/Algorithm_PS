#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> idx;
    bool reported[1001][1001] = {false,};
    int count[1001] = {0,};
    
    for(int i=0; i<id_list.size(); i++){
        idx[id_list[i]] = i;
    }
    
    for(int i=0; i<report.size(); i++){
        string p1 = report[i].substr(0, report[i].find(" "));
        string p2 = report[i].substr(report[i].find(" ")+1, report[i].length());
        int idx1 = idx[p1];
        int idx2 = idx[p2];
        
        if(reported[idx1][idx2])
            continue;
        else{
            reported[idx1][idx2] = true;
            count[idx2]++;
        }
    }
    
    for(int i=0; i<id_list.size(); i++){
        if(count[i]>=k){
            for(int j=0; j<id_list.size(); j++){
                if(reported[j][i])
                    answer[j]++;
            }
        }
    }
    
    return answer;
}