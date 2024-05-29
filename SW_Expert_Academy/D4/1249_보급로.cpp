#include<iostream>
#include<string>
#include<queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(int argc, char** argv)
{
		int test_case;
		int T, N;
	  int map[101][101] = { 0, };
	  int dp[101][101] = { 0, };
	  bool visited[101][101] = { false, };
		cin>>T;
   
		for(test_case = 1; test_case <= T; ++test_case) {
			  string str;
		    queue<pair<int, int>> q;
		    cin >> N;
		    for(int i=0; i<N; i++){
				    cin >> str;
			      for(int j=0; j<N; j++){
					      map[i][j] = str[j] - '0';
				        dp[i][j] = 0;
				        visited[i][j] = false;
			      }
		    }
      
			  q.push({0, 0});
		    visited[0][0] = true;
        
	      while(!q.empty()){
			      int x = q.front().first;
	          int y = q.front().second;
	          q.pop();
            
	          for(int i=0; i<4; i++){
			          int nx = x + dx[i];
	              int ny = y + dy[i];
		            if(0<=nx && nx<N && 0<=ny && ny<N){
				            if(!visited[nx][ny] || dp[nx][ny] > dp[x][y]+map[nx][ny]){
			                  visited[nx][ny] = true;
	                      dp[nx][ny] = dp[x][y]+map[nx][ny];
	                      q.push({nx, ny});
	                  }
	              }
	          }
	      }
        
	      cout << "#" << test_case << " " << dp[N-1][N-1] << endl;
		}
		return 0;
}
