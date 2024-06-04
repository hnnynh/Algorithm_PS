#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<pair<int, int>, bool> a, pair<pair<int, int>, bool> b) {
	return a.first.first < b.first.first;
}

int main() {

	int N, x, r;
	bool result = true;
	vector<pair<pair<int, int>, bool>> v;			// location, id, state
	stack<int> st;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> r;
		v.push_back({ {x - r, i}, 0 });
		v.push_back({ {x + r, i}, 1 });
	}

	sort(v.begin(), v.end(),  compare);
	
	for (int i = 0; i < v.size(); i++) {

		if (v[i].second == 0) {
			st.push(v[i].first.second);
		}
		else {
			if (st.top() != v[i].first.second) {
				result = false;
				break;
			}
			else {
				st.pop();
			}
		}
	}

	if (!st.empty())
		result = false;

	if (!result)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}