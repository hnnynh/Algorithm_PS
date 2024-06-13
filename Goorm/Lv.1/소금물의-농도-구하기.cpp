#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	int N, M;
	double water, salt;
	cin >> N >> M;
	
	water = N * 0.93 + M;
	salt = N * 0.07; 
	int answer = salt / (water + salt) * 10000;
	
	cout<<fixed;
  cout.precision(2);
	
	cout << answer / 100.0;
	
	return 0;
}