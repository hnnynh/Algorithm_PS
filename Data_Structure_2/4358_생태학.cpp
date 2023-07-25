// while(getline(cin, str)), while(cin >> str), while(!cin.eof())
// map 자동 정렬
// 소수점 출력 형식

#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	map<string, double> tree;
	string str;
	double p = 0.0;

	while (getline(cin, str)) {
		p++;
		if (tree.find(str) != tree.end())
			tree[str]++;
		else
			tree[str] = 1;
	}

	cout << fixed;
	cout.precision(4);

	for (auto it = tree.begin(); it != tree.end(); it++) {
		cout << it->first << " " << (it->second / p) * 100 << "\n";
	}

	return 0;
}