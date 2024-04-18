#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(auto w:works){
        pq.push(w);
    }
    
    while(n-->0 && !pq.empty()){
        int temp = pq.top();
        pq.pop();
        if(temp == 1)
            continue;
        pq.push(temp-1);
    }
    
    while(!pq.empty()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}
