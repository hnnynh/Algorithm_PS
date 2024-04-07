#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int ans = 100;
    vector<int> v(n+1, 0);
    vector<vector<int>> adj(n+1, v);
    
    for(int i=0; i<wires.size(); i++){
        adj[wires[i][0]][wires[i][1]] = 1;
        adj[wires[i][1]][wires[i][0]] = 1;
    }
    
    for(int i=0; i<wires.size(); i++){
        queue<int> q;
        vector<bool> visited(n+1, false);
        int cnt = 0;
        q.push(wires[i][0]);
        visited[wires[i][0]] = true;
                
        while(!q.empty()){
            int p = q.front();
            q.pop();
            cnt++;
            for(int j=1; j<n+1; j++){
                if(adj[p][j] && j != wires[i][1] && !visited[j]){
                    q.push(j);
                    visited[j] = true;
                }   
            }
        }    
        ans = min(ans, n-min(n-cnt, cnt)*2);
    }
    
    return ans;
}
