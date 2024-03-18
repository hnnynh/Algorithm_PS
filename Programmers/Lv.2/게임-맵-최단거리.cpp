#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    vector<int> row(maps[0].size(), 0);
    vector<vector<int>> d(maps.size(), row);
    vector<pair<int, int>> adj;
    adj.push_back({1,0});
    adj.push_back({-1,0});
    adj.push_back({0,1});
    adj.push_back({0,-1});
    
    queue<pair<int, int>> q;
    
    d[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty()){
        pair<int, int> temp = q.front();
        int ni = temp.first;
        int nj = temp.second;
        
        q.pop();
        
        for(int i=0; i<4; i++){
            if(ni+adj[i].first < 0 || ni+adj[i].first >= maps.size() || nj+adj[i].second < 0 || nj+adj[i].second >= maps[0].size())
                continue;
            
            if(maps[ni+adj[i].first][nj+adj[i].second] == 1){
                if(d[ni+adj[i].first][nj+adj[i].second] == 0){
                    q.push({ni+adj[i].first, nj+adj[i].second});
                    d[ni+adj[i].first][nj+adj[i].second] = d[ni][nj]+1;
                }
                else if(d[ni+adj[i].first][nj+adj[i].second] > d[ni][nj]+1){
                    d[ni+adj[i].first][nj+adj[i].second] = d[ni][nj]+1;
                }
            }
        }
    }
    
    if(d[maps.size()-1][maps[0].size()-1] == 0)
        return -1;
    
    return d[maps.size()-1][maps[0].size()-1];
}
