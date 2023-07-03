// int 배열 대신에 바로 출력하는 방법도 가능

#include<iostream>
#include<string>
#include<queue>

using namespace std;
int result[5000];

int main() {

	int N, K, idx = 0;
	queue<int> q;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}

	while (true) {
		for (int i = 0; i < K-1; i++) {
			int a = q.front();
			q.push(a);
			q.pop();
		}
		
		result[idx++] = q.front();
		q.pop();

		if (q.empty())
			break;
	}

	cout << '<';
	for (int i = 0; i < N - 1; i++) {
		cout << result[i] << ", ";
	}
	cout << result[N - 1] << '>';

	return 0;
}
