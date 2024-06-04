#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> dp(N + 1, 0);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++) {
		int min = dp[i - 1];
		if (i % 2 == 0) 
			min = min < dp[i / 2] ? min : dp[i / 2];
		if (i % 3 == 0) 
			min = min < dp[i / 3] ? min : dp[i / 3];
		dp[i] = min + 1;
	}

	cout << dp[N] << endl;

	return 0;

}