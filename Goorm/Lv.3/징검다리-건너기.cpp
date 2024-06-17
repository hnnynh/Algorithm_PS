#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, temp;	
	vector<int> rocks, dp;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> temp;
		rocks.push_back(temp);
		dp.push_back(temp);
	}
	dp.push_back(0);
	
	for(int i=3; i<=N; i++){
		temp = dp[i-1] < dp[i-2] ? dp[i-1] : dp[i-2];
		temp = temp < dp[i-3] ? temp : dp[i-3];
		dp[i] = temp + rocks[i];
	}
	
	cout << dp[N];
	
	return 0;
}
