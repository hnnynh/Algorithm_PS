#include<iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	long long N, K, result = 0;
	long long a[100000];

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a[N - 1 - i];
	}

	for (int i = 0; i < N; i++) {
		result += K / a[i];
		K %= a[i];
	}

	cout << result;

	return 0;
}