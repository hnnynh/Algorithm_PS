#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i=0; i<n; i++){
        if(visited[i])
            continue;
        queue<int> q;
        q.push(i);
        answer++;
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
            visited[f] = true;
            
            for(int j=0; j<n; j++){
                if(!visited[j] && computers[f][j]){
                    q.push(j);
                }
            }
        }
    }
    return answer;
}
