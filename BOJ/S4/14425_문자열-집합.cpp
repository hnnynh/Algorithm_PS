#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M, sum = 0;
	unordered_map<string, bool> s;
	string str;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert({ str, true });
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if(s[str] == true)
			sum++;
	}

	cout << sum;

	return 0;
}