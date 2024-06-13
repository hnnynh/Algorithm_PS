#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T, X, Y, N, temp;
	cin >> T;
	
	for(int i=0; i<T; i++){
		cin >> X >> Y >> N;
		
		if(abs(X)+abs(Y) > N){
			cout << "NO" << endl;
			continue;
		}
		
		temp = abs(X+Y) % 2;
		if(N % 2 == temp)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}
