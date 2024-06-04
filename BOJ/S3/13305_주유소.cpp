#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	long long N, c, result = 0, min = 1000000001;
	vector<int> city, gas;

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> c;
		city.push_back(c);
	}
	for (int i = 0; i < N; i++) {
		cin >> c;
		gas.push_back(c);
	}

	for (int i = 0; i < N - 1; i++) {
		if (gas[i] < min) {
			min = gas[i];
		}
		result += min * city[i];
	}

	cout << result;

	return 0;
}
