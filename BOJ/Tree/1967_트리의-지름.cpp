#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int M = 0, node;

void dfs(int n, int dia) {
	visited[n] = true;

	if (dia > M) {
		M = dia;
		node = n;
	}

	for (int i = 0; i < tree[n].size(); i++) {
		int next_node = tree[n][i].first;
		int next_dist = tree[n][i].second + dia;
		if (!visited[next_node]) {
			visited[next_node] = true;
			dfs(next_node, next_dist);
			visited[next_node] = false;
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, P, C, W;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> P >> C >> W;
		tree[P].push_back({ C,W });
		tree[C].push_back({ P,W });
	}

	dfs(1, 0);
	M = 0;
	for (int i = 0; i < 10001; i++)
		visited[i] = false;
	dfs(node, 0);

	cout << M;
	
	return 0;

}