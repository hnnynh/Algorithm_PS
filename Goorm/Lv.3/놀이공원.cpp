#include <iostream>

using namespace std;

int main() {
	int N, T, K;
	cin >> T;
	int ground[101][101];
	
	for(int i=0; i<T; i++){
		cin >> N >> K;
		int min = K * K + 1;
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				cin >> ground[j][k];
			}			
		}

		for(int j=0; j<=N-K; j++){
			for(int k=0; k<=N-K; k++){
				int temp = 0;
				for(int p=j; p<j+K; p++){
					for(int q=k; q<k+K; q++){
						temp += ground[p][q];
					}
				}
				min = min < temp ? min : temp;
			}
		}
		
		if(min == K*K+1)
			min = 0;
		cout << min << endl;
	}
	
	return 0;
}
