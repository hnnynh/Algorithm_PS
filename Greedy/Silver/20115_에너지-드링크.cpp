#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	long long N, c;
	double result = 0;
	vector<double> drink;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		drink.push_back(c);
	}
	sort(drink.begin(), drink.end());

	for (int i = 0; i < N - 1; i++) {
		result += drink[i] / 2;
	}
	result += drink[N - 1];

	cout.precision(10);
	cout << result;

	return 0;
}
