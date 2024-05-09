#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, v = 0, node = 0, c = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;      // 가중치, 정점
    vector<bool> visited(n, false);
    vector<int> a(n, -1);
    vector<vector<int>> adj(n, a);
    
    if(n == 1)
        return 0;
    
    for(auto c:costs){
        adj[c[0]][c[1]] = c[2];
        adj[c[1]][c[0]] = c[2];
    }
    
    pq.push({0, 0});
    while(v < n){
        c = pq.top().first;
        node = pq.top().second;
        pq.pop();
        
        if(visited[node])
            continue;
        visited[node] = true;
        v++;
        answer += c;
        
        for(int i=0; i<n; i++){
            if(adj[node][i] > 0 && !visited[i])
                pq.push({adj[node][i], i});
        }
    }
    
    return answer;
}
