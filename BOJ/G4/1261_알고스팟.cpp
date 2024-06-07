#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int M, N;
	string str;
	queue<pair<int, int>> q;
	int map[101][101] = { 0, };
	int dp[101][101];
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j] - '0';
			dp[i][j] = 2000000000;
		}
	}
	dp[0][0] = 0;
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || N <= nx || ny < 0 || M <= ny)
				continue;

			if (dp[nx][ny] > dp[x][y] + map[nx][ny]) {
				dp[nx][ny] = dp[x][y] + map[nx][ny];
				q.push({ nx, ny });
			}
		}
	}

	cout << dp[N - 1][M - 1];

	return 0;
}
