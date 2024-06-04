// 원형큐가 생각나면 deque

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {
	int N, temp, idx = 0;
	deque<pair<int, int>> bp;	// 풍선 번호, 종이 숫자

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		bp.push_back({ i + 1, temp });
	}

	cout << bp.front().first << ' ';
	idx += bp.front().second;
	bp.pop_front();

	for (int j = 0; j < N - 1; j++) {
		if (idx > 0) {
			for (int i = 0; i < idx - 1; i++) {
				bp.push_back(bp.front());
				bp.pop_front();
			}
			cout << bp.front().first << ' ';
			idx = bp.front().second;
			bp.pop_front();
		}
		else {
			for (int i = 0; i < idx * (-1) - 1; i++) {
				bp.push_front(bp.back());
				bp.pop_back();
			}
			cout << bp.back().first << ' ';
			idx = bp.back().second;
			bp.pop_back();

		}
	}

	return 0;
}
