// 반례 잘 생각하기

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	string board, temp, result;
	bool flag = true;
	vector<pair<char, int>> poly;
	cin >> board;

	for (int i = 0; i < board.length(); i++) {
		if (board[i] == 'X') {
			temp += 'X';
		}
		else if (board[i] == '.') {
			if (temp.length() > 0) {
				if (temp.length() % 2 != 0) {
					cout << -1;
					return 0;
				}
				else {
					poly.push_back({ 'A', temp.length() - (temp.length() % 4)});
					poly.push_back({ 'B', temp.length() % 4 });
				}
				temp = "";
				poly.push_back({ '.', 1 });
			}
			else
				poly.push_back({ '.', 1 });
		}
	}
	if (temp.length() > 0) {
		if (temp.length() % 2 != 0) {
			cout << -1;
			return 0;
		}
		else {
			poly.push_back({ 'A', temp.length() - (temp.length() % 4) });
			poly.push_back({ 'B', temp.length() % 4 });
		}
	}

	for (int i = 0; i < poly.size(); i++) {
		for (int j = 0; j < poly[i].second; j++) {
			result += poly[i].first;
		}
	}

	cout << result;
	return 0;

}
