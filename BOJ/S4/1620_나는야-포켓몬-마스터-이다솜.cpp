// map보다 unordered_map이 빠르다

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	unordered_map<string, int> up;
	vector<string> vp;
	int N, M;
	string str;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		up.insert({ str, i + 1 });
		vp.push_back(str);
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (('A' <= str[0] && str[0] <= 'Z') || ('a' <= str[0] && str[0] <= 'z')) {
			cout << up[str] << '\n';
		}
		else {
			cout << vp[stoi(str) - 1] << '\n';
		}
	}
	
	return 0;
}