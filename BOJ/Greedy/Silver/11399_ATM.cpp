#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	long long N, result = 0;
	long long p[100000];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}

	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		result += p[i] * (N - i);
	}

	cout << result;

	return 0;
}
