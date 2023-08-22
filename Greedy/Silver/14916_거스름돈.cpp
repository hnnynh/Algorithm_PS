#include<iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, cnt5 = 0, cnt2 = 0, odd = 1;
	cin >> n;

	if (n % 2 == 0)
		odd = 0;
	
	if (odd) {
		if ((n / 5) % 2 == 0) {
			cnt5 += n / 5 - 1;
			n = n % 5 + 5;
		}	
		else {
			cnt5 += n / 5;
			n = n % 5;
		}			
	}
	else {
		if ((n / 5) % 2 == 1) {
			cnt5 += n / 5 - 1;
			n = n % 5 + 5;
		}
		else {
			cnt5 += n / 5;
			n = n % 5;
		}
	}

	cnt2 = n / 2;

	if (cnt5 < 0 || cnt2 < 0)
		cout << "-1";
	else
		cout << cnt5 + cnt2;
	
	return 0;
}