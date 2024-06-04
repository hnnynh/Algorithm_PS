#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	long long N, result = 0, cnt = 0;
	long long c[100000];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c[i];
	}

	sort(c, c + N);
	for (int i = 0; i < N; i++) {
		if (++cnt % 3 == 0)
			continue;
		result += c[N - 1 - i];
	}

	cout << result;

	return 0;
}