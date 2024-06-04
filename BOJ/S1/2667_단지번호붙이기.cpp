#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int N;
	string str;
	int map[26][26] = { 0, };
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	bool visited[26][26] = { false, };
	vector<int> answer;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				int cnt = 0;
				queue<pair<int, int>> q;
				q.push({ i,j });

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					if (visited[x][y]) {
						q.pop();
						continue;
					}

					visited[x][y] = true;
					cnt++;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny] && map[nx][ny] == 1)
							q.push({ nx,ny });
					}
				}
				answer.push_back(cnt);
 			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

	return 0;
}
