#include<iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	if (N == 1 || N == 2 || N == 4 || N == 7)
		cout << "-1\n";
	else {
		switch (N % 5) {
		case 0:
			cout << N / 5 << endl;
			break;
		case 1:
		case 3:
			cout << N / 5 + 1 << endl;
			break;
		case 2:
		case 4:
			cout << N / 5 + 2 << endl;
			break;
		}
	}

	return 0;

}