// 기존 풀이 : vector로 비교
// 새로운 풀이 : queue <-> priority queue 비교

#include<iostream>
#include<queue>

using namespace std;

int main() {

	int T, N, M, pri, cnt;
	queue <pair<int, int>> q;	
	priority_queue<int> pq;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cnt = 0;

		for (int j = 0; j < N; j++) {
			cin >> pri;
			q.push({ j, pri });
			pq.push(pri);
		}

		while (!q.empty()) {
			int idx = q.front().first;
			int p = q.front().second;
			q.pop();

			if (pq.top() == p) {
				pq.pop();
				cnt++;
				if (idx == M) {
					cout << cnt << endl;
				}
			}
			else q.push({ idx, p });

		}
	}
	
	return 0;
}