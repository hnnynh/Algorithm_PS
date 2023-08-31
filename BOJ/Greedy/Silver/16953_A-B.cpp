#include<iostream>
#include<string>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int A, B, cnt = 0;
	cin >> A >> B;
	while (A < B) {
		if (B % 2 == 0)
			B /= 2;
		else if (B % 10 == 1)
			B /= 10;
		else
			break;
		cnt++;
	}
    
	if (A == B)
		cout << ++cnt;
	else
		cout << -1;

	return 0;
}