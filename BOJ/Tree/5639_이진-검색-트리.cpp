#include<iostream>
#include<vector>

using namespace std;

vector<int> tree;

void post(int left, int right) {
	if (left >= right)
		return;
	
	if (left == right - 1) {
		cout << tree[left] << '\n';
		return;
	}
		
	int idx = left + 1;
	while (tree[left] >= tree[idx] && idx < right) {
		idx++;			// 부모 노드 찾기
	}

	post(left + 1, idx);
	post(idx, right);
	cout << tree[left] << '\n';
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int num;
	
	while (cin >> num) {
		tree.push_back(num);
	}
	
	post(0, tree.size());

	return 0;
}