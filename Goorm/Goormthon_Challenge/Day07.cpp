#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, K, n, ans = 0;
	vector<vector<int>> board;
	int dx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
	int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
	
	cin >> N >> K;
	for(int i=0; i<N; i++){
		vector<int> temp;
		for(int j=0; j<N; j++){
			cin >> n;
			temp.push_back(n);
		}
		board.push_back(temp);
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int cnt = 0;
			
			if (board[i][j])
				continue;
			
			for(int k=0; k<8; k++){
				int ni = i + dx[k];
				int nj = j + dy[k];
				
				if(ni < 0 || nj < 0 || ni >= N || nj >= N || !board[ni][nj])
					continue;
				cnt++;
			}
			
			if(cnt == K)
				ans++;
		}
	}
	
	cout << ans << endl;
	return 0;
}