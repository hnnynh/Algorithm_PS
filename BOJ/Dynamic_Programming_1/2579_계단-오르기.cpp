#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int S, temp;
	vector<int> score;
	cin >> S;
	vector<int> dp(S + 1, 0);

	score.push_back(0);
	for (int i = 0; i < S; i++) {
		cin >> temp;
		score.push_back(temp);
	}
	dp[0] = score[0];
	dp[1] = score[1];

	if (S >= 2)
		dp[2] = score[1] + score[2];
	if (S >= 3)
		dp[3] = max(score[1], score[2]) + score[3];
	if (S >= 4) {
		for (int i = 4; i <= S; i++) {
			dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
		}
	}

	cout << dp[S] << endl;

	return 0;
}