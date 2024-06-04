#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int T, N, a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int temp = 0, ans = 1;
		vector<pair<int, int>> score;
		vector<int> idx;

		for (int j = 0; j < N; j++) {
			cin >> a >> b;
			score.push_back({ a,b });
		}

		sort(score.begin(), score.end());
		for (int j = 0; j < N; j++) {
			if (score[temp].second > score[j].second) {
				ans++;
				temp = j;
			}		
		}
		cout << ans << endl;
	}

	return 0;
}