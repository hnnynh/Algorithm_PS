#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, destx, desty;
int land[1001][1001];
int dist[1001][1001] = { 10000, };
bool visited[1001][1001] = { false, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void trav() {
	queue<pair<int, int>> q;
	dist[destx][desty] = 0;

	q.push({ destx, desty });

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		if (visited[curx][cury] || land[curx][cury] == 0)
			continue;
		visited[curx][cury] = true;

		for (int i = 0; i < 4; i++) {
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];

			if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M)
				continue;
			if (visited[nextx][nexty] || land[nextx][nexty] == 0)
				continue;
			dist[nextx][nexty] = dist[curx][cury] + 1;
			q.push({ nextx, nexty });
		}

	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);


	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> land[i][j];
			if (land[i][j] == 2) {
				destx = i;
				desty = j;
			}
		}
	}

	trav();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (land[i][j] == 0)
				cout << "0 ";
			else if (!visited[i][j])
				cout << "-1 ";
			else
				cout << dist[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;

}