// 문제 조건 제대로 확인하기

#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, P, L, M, t1, t2;
	string str;
	priority_queue<pair<int, int>> max_pq;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
	unordered_map<int, int> um;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		max_pq.push({ L,P });		// 난이도, 문제 번호
		min_pq.push({ L,P });
		um[P] = L;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {

		while (!max_pq.empty() && um[max_pq.top().second] != max_pq.top().first)
			max_pq.pop();
		while (!min_pq.empty() && um[min_pq.top().second] != min_pq.top().first)
			min_pq.pop();

		cin >> str;
		if (str == "recommend") {
			cin >> t1;
			if (t1 == 1) 
				cout << max_pq.top().second << '\n';		
			else 
				cout << min_pq.top().second << '\n';
		}
		else if (str == "add") {
			cin >> t1 >> t2;
			max_pq.push({ t2,t1 });
			min_pq.push({ t2,t1 });
			um[t1] = t2;
		}
		else if (str == "solved") {
			cin >> t1;
			um[t1] = 0;
		}

	}

	return 0;
}