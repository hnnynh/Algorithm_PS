#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, max = 0, node = 1;
    vector<bool> visited(n+1, false);
    vector<vector<bool>> adj(n+1, visited);
    vector<int> cost(n+1, 20001);
    queue<pair<int, int>> q;        // idx, level
    
    for(auto e:edge){
        adj[e[0]][e[1]] = true;
        adj[e[1]][e[0]] = true;
    }
    
    cost[1] = 0;
    while(true){
        int min = 50001;
        visited[node] = true;
        
        for(int i=2; i<=n; i++){
            if(!visited[i] && adj[node][i] && cost[node]+1 < cost[i])
                cost[i] = cost[node] + 1;
        }
        
        for(int i=2; i<=n; i++){
            if(!visited[i] && cost[i] < min){
                min = cost[i];
                node = i;
            }
        }
        
        if(min == 50001)
            break;
    }
    
    for(int i=1; i<=n; i++){
        max = cost[i] < max ? max : cost[i];
    }
    for(int i=1; i<=n; i++){
        if(cost[i] == max)
            answer++;
    }
    
    return answer;
}
