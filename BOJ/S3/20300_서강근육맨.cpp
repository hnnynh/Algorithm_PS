#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N;
	long long result = 0, c;
	vector<long long> t;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		t.push_back(c);
	}
	sort(t.begin(), t.end());

	if (N % 2 == 0) {
		for (int i = 0; i < N / 2; i++) {
			result = max(result, t[i] + t[N - 1 - i]);
		}
	}
	else {
		result = t[N - 1];
		N--;
		for (int i = 0; i < N / 2; i++) {
			result = max(result, t[i] + t[N - 1 - i]);
		}
	}

	cout << result;

	return 0;
}
