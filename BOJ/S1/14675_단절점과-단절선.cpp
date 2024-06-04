#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	vector<int> graph[100001];
	int N, Q, a, b;

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		if (a == 1) {
			if (graph[b].size() > 1)
				cout << "yes\n";
			else
				cout << "no\n";
		}
		else
			cout << "yes\n";
	}
	
	return 0;
}