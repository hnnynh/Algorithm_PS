#include <iostream>

using namespace std;

int main() {
	long long W, R;
	long long result;
	cin >> W >> R;
	
	result = W * (1+((double)R/30));

	cout << result;
	
	return 0;
}