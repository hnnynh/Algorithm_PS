#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, cur = 0, sum = 0, done = 0, js = jobs.size(), idx = 0;
    vector<int> v;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    sort(jobs.begin(), jobs.end());
    
    while(done < js){
        while(idx < js && cur >= jobs[idx][0])
            pq.push({ jobs[idx][1], jobs[idx++][0]} );
        
        if(pq.empty()){
            cur = jobs[idx][0];
            continue;
        }
        
        int ta = pq.top().first;
        int st = pq.top().second;
        pq.pop();
        cur += ta;
        sum += cur - st;
        done++;
    }
    
    return sum / js;
}
