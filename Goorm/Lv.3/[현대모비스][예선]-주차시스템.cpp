#include <iostream>
#include <vector>
#include <queue>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

using namespace std;
int main() {
	int N, M, temp, answer = 0;
	vector<vector<int>> parking(2001, vector<int>(2001, 0));
	vector<vector<bool>> visited(2001, vector<bool>(2001, false));
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> parking[i][j];
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(parking[i][j]!=1 && !visited[i][j]){
				queue<pair<int, int>> q;
				temp = 0;
				q.push({i, j});
				
				while(!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if(visited[x][y])
						continue;
					visited[x][y] = true;
					
					if(parking[x][y] == 0)
						temp += 1;
					else
						temp -= 2;
					
					for(int k=0; k<4; k++){
						int nx = x + dx[k];
						int ny = y + dy[k];
						if(0<=nx && 0<=ny && nx<N && ny<M && !visited[nx][ny] && parking[nx][ny]!=1){
							q.push({nx, ny});
						}
						
					}
				}
				answer = answer < temp ? temp : answer;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}
