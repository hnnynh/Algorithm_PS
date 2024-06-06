#include<iostream>

using namespace std;

int N, d, k, c;
int sushi[30001] = { 0, };

int check(int start) {
	int cnt = 0;
	bool eat[30001] = { false, };

	for (int i = 0; i < k; i++) {
		int idx = start + i;
		if (idx >= N)
			idx -= N;
		if (!eat[sushi[idx]]) {
			if (sushi[idx] != c)
				cnt++;
			eat[sushi[idx]] = true;
		}
	}

	return cnt;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int max = 0;
	
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++)
		cin >> sushi[i];

	for (int i = 0; i < N; i++) {
		int temp = check(i);
		max = max < temp ? temp : max;
	}
	
	cout << max + 1;

	return 0;
}
