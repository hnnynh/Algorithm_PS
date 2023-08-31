// 시간 초과 주의
// 스택

#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, temp;
	stack<pair<int, int>> st;

	cin >> N;
	st.push({ 100000001, 0 });
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		while (st.top().first < temp) {
			st.pop();
		}
		cout << st.top().second << ' ';
		st.push({ temp, i });
	}

	return 0;
}