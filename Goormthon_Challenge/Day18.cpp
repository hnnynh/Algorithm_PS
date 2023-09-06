#include <iostream>

using namespace std;

int main() {
	
	pair<long long, long long> sq[101][101];
	long long N, M, x, y, start, end, ans = 0;
	bool xy = true; // true - x 변화, false - y 변화
	char d;
	
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		cin >> x >> y >> d;
		switch(d){
			case 'U':
				xy = true;
				start = 1;
				end = x;
				break;
			case 'D':
				xy = true;
				start = x;
				end = N;
				break;
			case 'L':
				xy = false;
				start = 1;
				end = y;
				break;
			case 'R':
				xy = false;
				start = y;
				end = N;
				break;
		}
		
		if(xy){
			for(int j = start; j <= end; j++){
				sq[j][y].first++;
			}
		}
		else{
			for(int j = start; j <= end; j++){
				sq[x][j].second++;
			}
		}
	}
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(sq[i][j].first && sq[i][j].second){
				ans += sq[i][j].first * sq[i][j].second;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}