#include<iostream>
#include<vector>

using namespace std;
vector<int> tree[100001];
int parent[100001];
int N;

void dfs(int node) {
	for (int i = 0; i < tree[node].size(); i++) {
		if (parent[tree[node][i]] == 0) {
			parent[tree[node][i]] = node;
			dfs(tree[node][i]);
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	
	int v1, v2;

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> v1 >> v2;
		tree[v1].push_back(v2);
		tree[v2].push_back(v1);
	}
	
	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}