#include <iostream>

using namespace std;

int main() {
	int N, K;
	int A[10] = {0,};
	int B[10] = {0,};
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> A[i];
	for(int i=1; i<=N; i++)
		cin >> B[i];
	cin >> K;
	
	B[N] += K;
	for(int i=N; i>0; i--){
		if(B[i] > A[i]){
			B[i-1] += B[i] / (A[i]+1);
			B[i] = B[i] % (A[i]+1);
		}
	}
	
	for(int i=1; i<=N; i++)
		cout << B[i];
	
	return 0;
}
