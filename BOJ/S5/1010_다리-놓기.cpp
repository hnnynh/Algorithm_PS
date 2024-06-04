// Combination - DP 가능

#include<iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	long long T, N, M, u = 1, d = 1;

	cin >> T;
	for (int i = 0; i < T; i++) {
		u = 1;
		d = 1;
		cin >> N >> M;
		for (int j = M; j > max(M - N, N); j--) {
			u *= j;
		}
		for (int j = min(M - N, N); j > 0; j--) {
			d *= j;
		}
		cout << u / d << endl;
	}

	return 0;

}