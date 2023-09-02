#include <iostream>
using namespace std;

int main() {
	long long N, ans = 0;
	cin >> N;
	
	ans += N/14;
	N %= 14;
	ans += N/7;
	N %= 7;
	ans += N;
	
	cout << ans << endl;
		
	return 0;
}