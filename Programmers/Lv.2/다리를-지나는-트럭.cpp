#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int b_w = 0, cur = 1, idx = 0;    
    queue<pair<int, int>> q;    // 진입 시간, 무게
    b_w += truck_weights[idx];
    q.push({cur++, truck_weights[idx++]});
    
    while(idx < truck_weights.size()){
        if(cur - q.front().first >= bridge_length){
            b_w -= q.front().second;
            q.pop();
        } 
        if(q.size() < bridge_length && b_w + truck_weights[idx] <= weight){
            b_w += truck_weights[idx];
            q.push({cur, truck_weights[idx++]});
        }
       if(q.empty())
            break;
        cur++;
    }
    
    while(!q.empty()){
        if(cur - q.front().first >= bridge_length){
            b_w -= q.front().second;
            q.pop();
        } 
        if(q.empty())
            break;
        cur++;
    }
    
    return cur;
}
