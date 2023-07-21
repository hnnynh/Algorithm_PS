// priority_queue 정렬 기준 -> 구조체에서 operator() 정의

#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	priority_queue<pair<int, int>> pq;
	int N, x;
	string str;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top().second * (-1) << "\n";
				pq.pop();
			}
			else 
				cout << "0\n";		
		}
		else {
			if (x > 0)
				pq.push({ x * (-1), x * (-1)});
			else 
				pq.push({ x, x * (-1) });
			
		}
	}

	return 0;
}