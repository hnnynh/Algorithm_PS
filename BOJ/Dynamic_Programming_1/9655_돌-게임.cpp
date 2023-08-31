// DP를 이용하면 DP[i] = min(DP[i - 1] + 1, DP[i - 3] + 1); 도 가능

#include<iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	if (N % 2)
		cout << "SK\n";
	else
		cout << "CY\n";

	return 0;

}