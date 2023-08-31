#include <iostream>

using namespace std;

int main() {
	int T, c0, c1, c2;
	long long sum = 0;
	char op;
	
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> c1 >> op >> c2;
		switch(op){
			case '+':
				sum += c1 + c2;
				break;
			case '-':
				sum += c1 - c2;
				break;
			case '*':
				sum += c1 * c2;
				break;
			case '/':
				sum += c1 / c2;
				break;
		}
	}
	
	cout << sum;
	
	return 0;
}