#include <iostream>

using namespace std;

int main() {
	int N, T, M, c = 0, temp, t, m;
	
	cin >> N;
	cin >> T >> M;
	
	for(int i=0; i<N; i++){
		cin >> temp;
		c += temp;
	}
	
	t = c / 60;
	m = c % 60;
	
	M += m;
	if(M >= 60){
		M -= 60;
		T++;
	}
	
	T += t;
	if(T >= 24){
		T %= 24;
	}
	
	cout << T << ' ' << M;
	
	return 0;
}