#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, S, T;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<>> pq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		v.push_back({ S,T });
	}

	sort(v.begin(), v.end());
	pq.push(v[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
		}
	}

	cout << pq.size();
	
	return 0;

}