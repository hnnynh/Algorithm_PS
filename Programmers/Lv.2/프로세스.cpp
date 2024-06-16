#include <string>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i=0; i<priorities.size(); i++){
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int f = q.front().first;
        int i = q.front().second;
        q.pop();
        
        if(f == pq.top()){
            answer++;
            if(location == i)
                break;
            pq.pop();
        }
        else
            q.push({f, i});
    }
    
    return answer;
}
