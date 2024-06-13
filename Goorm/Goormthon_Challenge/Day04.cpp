#include <iostream>

using namespace std;

int main() {
	long long mat = 0;
	int prev = 0, N, k;
	bool flag = true;	// 오름차순
	
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> k;
		mat += k;
		if(flag){
			if(prev > k)
				flag = false;
		}
		else{
			if(prev < k){
				mat = 0;
				break;
			}			
		}
		prev = k;
	}
	
	cout << mat;
	
	return 0;
}