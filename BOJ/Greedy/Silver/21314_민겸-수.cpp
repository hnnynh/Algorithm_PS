#include<iostream>
#include<string>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int cal = 0;
	string MK, temp, max, min;
	cin >> MK;

	for (int i = 0; i < MK.length(); i++) {
		if (MK[i] == 'M') {
			cal++;
		}
		else if (MK[i] == 'K') {
			max += '5';
			for (int i = 0; i < cal; i++)
				max += '0';
			cal = 0;
		}
	}
	if (cal > 0) {
		for (int i = 0; i < cal; i++) {
			max += '1';
		}
		cal = 0;
	}
	
	for (int i = 0; i < MK.length(); i++) {
		if (MK[i] == 'M') {
			cal++;
		}
		else if (MK[i] == 'K') {
			if (cal > 0) {
				min += '1';
				for (int i = 0; i < cal - 1; i++) {
					min += '0';
				}
				cal = 0;
			}
			min += '5';
		}
	}
	if (cal > 0) {
		min += '1';
		for (int i = 0; i < cal - 1; i++) {
			min += '0';
		}
	}

	cout << max << endl;
	cout << min << endl;

	return 0;

}
