#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> m;
    map<string, bool> u;
    int type = 0, start = 0, end = 0, mins = 100000, mine = 200000, cnt = 0;
    
    for(auto g:gems){
        m[g] = 0;
        if(!u[g]){
            type++;
            u[g] = true;
        }    
    } 
    
    while(end < gems.size()){
        if(m[gems[end]] == 0)
            cnt++;
        m[gems[end]]++;
        
        while(m[gems[start]] > 1 && start < end){
            m[gems[start++]]--;
        }
        
        if(cnt == type && end-start<mine-mins){
            mins = start;
            mine = end;
        }
        end++;
    }
    
    answer.push_back(mins+1);
    answer.push_back(mine+1);

    return answer;
}
