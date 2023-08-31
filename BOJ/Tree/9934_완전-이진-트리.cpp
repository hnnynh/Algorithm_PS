// 분할 정복
// 반복문 범위 주의

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<int> tree[10];
vector<int> arr;

void make_tree(int depth, int left, int right) {
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	tree[depth].push_back(arr[mid]);

	make_tree(depth + 1, left, mid);
	make_tree(depth + 1, mid + 1, right);
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int K, num;
	
	cin >> K;
	for (int i = 0; i < pow(2, K) - 1; i++) {
		cin >> num;
		arr.push_back(num);
	}
	
	make_tree(0, 0, arr.size());
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			cout << tree[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}