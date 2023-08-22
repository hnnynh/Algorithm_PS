#include<iostream>

using namespace std;

int tree[500001] = { 0, };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int N, W, U, V;
	double cnt = 0;

	cin >> N >> W;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		tree[U]++;
		tree[V]++;
	}

	for (int i = 2; i < N + 1; i++) {
		if (tree[i] == 1)
			cnt++;
	}

	cout.precision(10);
	cout << W / cnt;
	return 0;
}


/*
#include<iostream>
#include<vector>

using namespace std;

vector<int> tree[500001];
bool visited[500001] = { 0, };
double cnt = 0;

void dfs(int n) {
	visited[n] = true;

	if (tree[n].size() == 1 && visited[tree[n][0]]) {
		cnt++;
		return;
	}

	for (int i = 0; i < tree[n].size(); i++) {
		if(!visited[tree[n][i]])
			dfs(tree[n][i]);
	}
	visited[n] = false;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int N, W, U, V;
	
	cin >> N >> W;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		tree[U].push_back(V);
		tree[V].push_back(U);
	}

	dfs(1);

	cout.precision(10);
	cout << W / cnt;
	return 0;
}
*/