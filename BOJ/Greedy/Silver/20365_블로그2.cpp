#include<iostream>
#include<string>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, blue = 0, red = 0, flag = 0, result = 0;
	string str;

	cin >> N >> str;
	if (str[0] == 'B')
		blue++;
	else if (str[0] == 'R')
		red++;
	for (int i = 1; i < N; i++) {
		if (str[i] == 'B' && str[i] != str[i - 1])
			blue++;
		else if (str[i] == 'R' && str[i] != str[i - 1])
			red++;
	}
	
	cout << min(blue, red) + 1;

	return 0;
}