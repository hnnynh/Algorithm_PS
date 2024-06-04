#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
int city[51][51] = { 0, };
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<vector<int>> pick;

void dfs(vector<int> st, int idx) {
	if (st.size() == M) {
		pick.push_back(st);
		return;
	}
	if (idx >= chicken.size())
		return;
	
	dfs(st, idx + 1);
	st.push_back(idx);
	dfs(st, idx + 1);
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int min = 2000000000;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				home.push_back({ i,j });
			else if (city[i][j] == 2)
				chicken.push_back({ i, j });
		}
	}
	dfs({}, 0);

	for (int i = 0; i < pick.size(); i++) {
		int cal = 0;
		for (int j = 0; j < home.size(); j++) {
			int m = 10000;
			for (int k = 0; k < M; k++) {
				int r = abs(chicken[pick[i][k]].first - home[j].first);
				int c = abs(chicken[pick[i][k]].second - home[j].second);
				m = m < r + c ? m : r + c;
			}
			cal += m;
		}
		min = cal < min ? cal : min;
	}

	cout << min;

	return 0;
}
