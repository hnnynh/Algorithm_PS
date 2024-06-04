// leaf node 1 반환 위치 주의

#include<iostream>
#include<vector>

using namespace std;

vector<int> arr[51];
int enode;

int dfs(int node) {

	int result = 0;
	for (int i = 0; i < arr[node].size(); i++) {
		if (arr[node][i] == enode)
			continue;
		result += dfs(arr[node][i]);
	}

	if (result == 0)
		return 1;
	else
		return result;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int N, root, parent;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parent;
		if (parent == -1)
			root = i;
		else 
			arr[parent].push_back(i);
	}
	
	cin >> enode;
	if (root != enode)
		cout << dfs(root);
	else
		cout << "0";

	return 0;
}