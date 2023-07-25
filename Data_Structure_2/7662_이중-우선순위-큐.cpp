// 출력 형식 제대로 확인하기 '\n'

#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int T, k, temp;
	char c;

	cin >> T;
	for (int i = 0; i < T; i++) {
		priority_queue<int> max_pq;
		priority_queue<int, vector<int>, greater<>> min_pq;
		unordered_map<int, int> um;

		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> c >> temp;

			while (!max_pq.empty() && um[max_pq.top()] <= 0)
				max_pq.pop();
			while (!min_pq.empty() &&um[min_pq.top()] <= 0)
				min_pq.pop();

			if (c == 'D') {
				if (max_pq.empty() || min_pq.empty())
					continue;

				if (temp > 0) {		// 최댓값 삭제
					um[max_pq.top()]--;
					max_pq.pop();
				}
				else {      // 최솟값 삭제
					um[min_pq.top()]--;
					min_pq.pop();
				}
			}
			else if (c == 'I') {
				max_pq.push(temp);
				min_pq.push(temp);
				um[temp]++;
			}
		}

		while (!max_pq.empty() && um[max_pq.top()] <= 0)
			max_pq.pop();
		while (!min_pq.empty() && um[min_pq.top()] <= 0)
			min_pq.pop();

		if (max_pq.empty() || min_pq.empty())
			cout << "EMPTY\n";
		else 
			cout << max_pq.top() << " " << min_pq.top() << "\n";
	}

	return 0;
}