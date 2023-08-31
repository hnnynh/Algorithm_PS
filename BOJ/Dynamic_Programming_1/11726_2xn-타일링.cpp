#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int T, N;
	cin >> N;
	vector<int> dp(N + 1, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 10007;
	}
	cout << dp[N] << endl;

	return 0;

}