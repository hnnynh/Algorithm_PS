#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) 
		return a.first < b.first;
	else 
		return a.second < b.second;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, S, E, cnt = 0, prev = 0;
	vector<pair<int, int>> meeting;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> E;
		meeting.push_back({ S,E });
	}

	sort(meeting.begin(), meeting.end(), compare);

	for (int i = 0; i < N; i++) {
		if (prev <= meeting[i].first) {
			prev = meeting[i].second;
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;

}