#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> dp(N + 1, 0);
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		int m = INT_MAX;
		for (int j = 1; j * j <= i; j++) {
			int temp = i - j * j;
			m = dp[temp] + 1 < m ? dp[temp] + 1 : m;
		}
		dp[i] = m;
	}

	cout << dp[N] << endl;

	return 0;

}