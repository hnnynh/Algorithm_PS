// 정해 코드는 DP로 풀이

#include <iostream>

using namespace std;

int main() {
	long long N;
	int A, B, min = 500001;
	cin >> N >> A >> B;
	
	int cA = N / A + 1;
	for(int i=0; i<cA; i++){
		if((N-A*i)%B == 0){
			if((N-A*i)/B + i < min)
				min = (N-A*i)/B + i;
		}
	}
	
	if(min == 500001)
		cout << "-1\n";
	else
		cout << min << endl;
	
	return 0;
}