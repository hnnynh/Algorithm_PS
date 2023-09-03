#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> M;
vector<vector<bool>> visited;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int N, K;

int count(int x, int y){
	
	visited[x][y] = true;
	queue<pair<int, int>> q;
	int cnt = 0;
	q.push({x, y});
	
	while(!q.empty()){
		int xi = q.front().first;
		int yi = q.front().second;
		q.pop();
		cnt++;
		
		for(int i=0; i<4; i++){
			int nx = xi + dx[i];
			int ny = yi + dy[i];
		
			if(nx<0 || nx>=N || ny<0 || ny>=N || M[nx][ny] != M[x][y] || visited[nx][ny])
				continue;
			visited[nx][ny] = true;
			q.push({nx, ny});	
		}
	}
	
	return cnt;
}


int main() {
	
	int m;
	vector<int> danji(31);
	
	cin >> N >> K;
	
	for(int i=0; i<N; i++){
		vector<int> temp;
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
			if(visited[i][j])
				continue;
			if(K <= count(i, j))
				danji[M[i][j]]++;
		}
	}

	int ans = 0;
	for(int i=0; i<danji.size(); i++){
		if(danji[i] >= danji[ans])
			ans = i;
	}
	
	cout << ans << endl;
	
	return 0;
}