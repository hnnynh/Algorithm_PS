#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int day = 0;
    vector<int> answer;
    queue<pair<int, int>> q;
    
    for(int i=0; i<progresses.size(); i++){
        q.push({progresses[i], speeds[i]});
    }
    
    while(!q.empty()){
        day++;
        int cnt = 0;
        int p = q.front().first;
        int s = q.front().second;
        
        while(p+s*day >= 100){
            cnt++;
            q.pop();
            p = q.front().first;
            s = q.front().second;
        }
        
        if(cnt > 0)
            answer.push_back(cnt);
    }
    
    return answer;
}
