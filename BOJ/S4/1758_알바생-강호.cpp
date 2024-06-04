#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	long long N, result = 0;
	long long tip[100000];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tip[i];
	}

	sort(tip, tip + N);

	for (int i = 0; i < N; i++) {
		if (tip[N - 1 - i] - i <= 0)
			continue;
		else
			result += tip[N - 1 - i] - i;
	}

	cout << result;

	return 0;
}
