#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<int>> m;
    vector<vector<bool>> visited;
    
    for(int i=0; i<maps.size(); i++){
        vector<int> t1;
        vector<bool> t2;
        for(int j=0; j<maps[0].size(); j++){
            if(maps[i][j] == 'X')
                t1.push_back(0);
            else
                t1.push_back(maps[i][j]-'0');
            t2.push_back(false);
        }
        m.push_back(t1);
        visited.push_back(t2);
    }
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            if(m[i][j] > 0 && !visited[i][j]){
                queue<pair<int, int>> q;
                int sum = 0;
                q.push({i,j});
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if(visited[x][y])
                        continue;
                    visited[x][y] = true;
                    sum += m[x][y];
                    
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        
                        if(0<=nx && nx<maps.size() && 0<=ny && ny<maps[0].size() && !visited[nx][ny] && m[nx][ny] > 0)
                            q.push({nx, ny});
                    }
                }
                
                answer.push_back(sum);
            }
        }
    }
    if(answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}
