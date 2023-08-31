// set으로 중복 제거
// dfs로 브루트포스

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<set>

using namespace std;

string str;
vector<pair<int, int>> v;
stack<int> st;
set<string> result;
bool check[201];

void dfs(int index, int delete_cnt) {

    if (delete_cnt >= 1) {
        string temp = "";
        for (int i = 0; i < str.length(); i++) {
            if (!check[i]) temp += str[i];
        }
        result.insert(temp);
    }

    for (int i = index; i < v.size(); i++) {
        check[v[i].first] = 1;
        check[v[i].second] = 1;

        dfs(i + 1, delete_cnt + 1);
        check[v[i].first] = 0;
        check[v[i].second] = 0;
    }
}

int main() {

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ')') {
			v.push_back({ st.top(), i });
			st.pop();
		}
		else if (str[i] == '(') {
			st.push(i);
		}
	}

    dfs(0, 0);

    for (auto iter = result.begin(); iter != result.end(); iter++)
        cout << *iter << endl;
	
	return 0;
}