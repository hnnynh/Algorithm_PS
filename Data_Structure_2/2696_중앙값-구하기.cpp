#include<iostream>
#include<queue>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int T, M, temp;

	cin >> T;

	for (int p = 0; p < T; p++) {
		priority_queue<int> pq1;	// 내림차순 - left
		priority_queue<int, vector<int>, greater<>> pq2;	// 오름차순 - right

		cin >> M;
		cout << M / 2 + 1 << '\n';

		cin >> temp;
		pq1.push(temp);
		cout << pq1.top() << ' ';

		for (int i = 1; i < M; i++) {

			cin >> temp;
			
			if (pq1.top() < temp)
				pq2.push(temp);
			else
				pq1.push(temp);

			while (pq1.size() > pq2.size()) {
				pq2.push(pq1.top());
				pq1.pop();
			}
			while (pq1.size() < pq2.size() + 1) {
				pq1.push(pq2.top());
				pq2.pop();
			}
			
			if (i % 20 == 0)
				cout << '\n';
			if (i % 2 == 0) 
				cout << pq1.top() << ' ';		// 중간값 출력
		}
		cout << '\n';
	}

	return 0;
}