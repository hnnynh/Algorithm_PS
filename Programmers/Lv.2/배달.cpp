#include <vector>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0, idx;
    vector<int> r(N+1, 20000001);
    vector<vector<int>> adj(N+1, r);
    vector<bool> visited(N+1, false);
    
    for(int i=0; i<road.size(); i++){
        if(adj[road[i][0]][road[i][1]] > road[i][2]){
            adj[road[i][0]][road[i][1]] = road[i][2];
            adj[road[i][1]][road[i][0]] = road[i][2];
        }
    }
    for(int i=1; i<=N; i++){
        adj[i][i] = 0;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        if(adj[1][i] <= K)
            answer++;
    }
    
    return answer;
}
