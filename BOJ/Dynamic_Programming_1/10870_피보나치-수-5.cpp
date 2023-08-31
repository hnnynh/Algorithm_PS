#include<iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, num[21];
	num[0] = 0;
	num[1] = 1;

	cin >> n;
	for (int i = 2; i <= n; i++) {
		num[i] = num[i - 1] + num[i - 2];
	}

	cout << num[n] << endl;

	return 0;

}