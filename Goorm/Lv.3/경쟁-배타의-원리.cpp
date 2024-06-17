#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K, x1, y1, x2, y2, minX = 1001, maxX = 0, minY = 1001, maxY = 0, answer = 0;
	vector<vector<int>> meta(1001, vector<int>(1001, 0));
	
	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		minX = minX < x1 ? minX : x1;
		maxX = maxX < x2 ? x2 : maxX;
		minY = minY < y1 ? minY : y1;
		maxY = maxY < y2 ? y2 : maxY;
		
		meta[x1][y1]++;
		meta[x1][y2]--;
		meta[x2][y1]--;
		meta[x2][y2]++;
	}
	
	for(int i=minX; i<maxX; i++){
		for(int j=minY; j<maxY; j++)
			meta[i][j+1] += meta[i][j];
	}
	for(int i=minX; i<maxX; i++){
		for(int j=minY; j<maxY; j++)
			meta[i+1][j] += meta[i][j];
	}
	for(int i=minX; i<maxX; i++){
		for(int j=minY; j<maxY; j++){
			if(meta[i][j] == K)
				answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}
