#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, K, Q;
char arr[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void check(int x, int y){
	char c = arr[x][y];
	bool visited[N+1][N+1] = {false,};
	vector<pair<int, int>> temp;
	queue<pair<int, int>> q;
	
	q.push({x, y});
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if(visited[cx][cy])
			continue;
		visited[cx][cy] = true;
		temp.push_back({cx, cy});
		
		for(int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx <= 0 || nx > N || ny <= 0 || ny > N || visited[nx][ny])
				continue;
			if(arr[nx][ny] != c)
				continue;
			
			q.push({nx, ny});
		}
	}
	
	if(temp.size() >= K){
		for(int i=0; i<temp.size(); i++){
			int cx = temp[i].first;
			int cy = temp[i].second;
			
			arr[cx][cy] = '.';
		}
	}
}

int main() {
	string str;
	char c;
	int x, y;
	cin >> N >> K >> Q;
	
	for(int i=1; i<=N; i++){
		cin >> str;
		for(int j=1; j<=N; j++){
			arr[i][j] = str[j-1];
		}
	}

	for(int i=0; i<Q; i++){
		cin >> x >> y >> c;
		arr[x][y] = c;
		check(x, y);
	}

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
	
	return 0;
}