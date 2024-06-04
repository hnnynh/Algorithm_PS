#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, result = 0;
	int w[100000];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}

	sort(w, w + N);
	for (int i = 0; i < N; i++) {
		result = max(result, (N - i) * w[i]);
	}

	cout << result;

	return 0;
}