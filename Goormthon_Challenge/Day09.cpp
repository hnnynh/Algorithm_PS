#include <iostream>
#include <vector>

using namespace std;

int main() {
	int dy[5] = {1, 0, -1, 0, 0};
	int dx[5] = {0, 1, 0, -1, 0};
	
	vector<vector<char>> land;
	vector<vector<int>> value;
	int N, K, y, x, ans = 0;
	char c;
	
	cin >> N >> K;
	for(int i=0; i<N; i++){
		vector<char> temp;
		vector<int> temp_v;
		for(int j=0; j<N; j++){
			cin >> c;
			temp.push_back(c);
			temp_v.push_back(0);
		}
		land.push_back(temp);
		value.push_back(temp_v);
	}
	
	for(int i=0; i<K; i++){
		cin >> y >> x;
		for(int j=0; j<5; j++){
			int n1 = y + dy[j] - 1;
			int n2 = x + dx[j] - 1;
			
			if(n1 < 0 || n1 >= N || n2 < 0 || n2 >= N || land[n1][n2] == '#')
				continue;
			else if(land[n1][n2] == '0')
				value[n1][n2]++;
			else
				value[n1][n2] += 2;
				
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(ans < value[i][j])
				ans = value[i][j];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}