#include<iostream>
#include<vector>

using namespace std;
pair<char, char> tree[26];
int parent[100001];
int N;

void pre(char node) {
	if (node != '.') {
		cout << node;
		pre(tree[node - 'A'].first);
		pre(tree[node - 'A'].second);
	}
}
void in(char node) {
	if (node != '.') {
		in(tree[node - 'A'].first);
		cout << node;
		in(tree[node - 'A'].second);
	}
}
void post(char node) {
	if (node != '.') {
		post(tree[node - 'A'].first);
		post(tree[node - 'A'].second);
		cout << node;
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	char a, b, c;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		tree[a - 'A'] = { b,c };
	}

	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');
	cout << '\n';

	return 0;
}