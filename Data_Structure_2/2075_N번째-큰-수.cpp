// 중간 과정에 pq.pop() 없으면 메모리 초과

#include<iostream>
#include<queue>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	priority_queue<int> pq;
	int N, temp;
	cin >> N;

	for (int i = 0; i < N * N; i++) {
		cin >> temp;
		pq.push(temp * (-1));
		if (pq.size() > N)
			pq.pop();
	}

	cout << (-1) * pq.top();
	
	return 0;
}