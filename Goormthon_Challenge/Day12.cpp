// 재귀 -> Runtime Error 발생

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> M;
vector<vector<bool>> visited;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int N;

void bfs(int x, int y){
	
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({x, y});
	
	while(!q.empty()){
		int xi = q.front().first;
		int yi = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = xi + dx[i];
			int ny = yi + dy[i];
		
			if(nx<0 || nx>=N || ny<0 || ny>=N || !M[nx][ny] || visited[nx][ny])
				continue;
			visited[nx][ny] = true;
			q.push({nx, ny});		
		}
	}
}


int main() {
	
	int m, ans = 0;
	cin >> N;
	
	for(int i=0; i<N; i++){
		vector<bool> temp;
		vector<bool> v;
		for(int j=0; j<N; j++){
			cin >> m;
			temp.push_back(m);
			v.push_back(0);
		}
		M.push_back(temp);
		visited.push_back(v);
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j] || !M[i][j])
				continue;
			ans++;
			bfs(i, j);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}