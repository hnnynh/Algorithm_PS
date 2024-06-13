#include <iostream>

using namespace std;

int main() {
	
	int N, M, s, e;
	int h[1001] = {0,};
	bool r[1001] = {false,};
	cin >> N >> M;
	
	for(int i=1; i<=N; i++)
		cin >> h[i];
	
	for(int i=1; i<=M; i++){
		cin >> s >> e;
		
		for(int j=s; j<=e; j++){
			h[j] += 1;
			r[j] = true;
		}
			
		if(i % 3 == 0){
			for(int j=1; j<=N; j++){
				if(r[j])
					h[j] -= 1;
			}
			for(int j=1; j<=N; j++){
				r[j] = false;
			}
		}
	}
	
	for(int i=1; i<=N; i++)
		cout << h[i] << " ";
	
	return 0;
}
