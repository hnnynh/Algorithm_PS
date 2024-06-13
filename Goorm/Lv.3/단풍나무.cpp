#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
	vector<vector<int>> park(41, vector<int>(41, 0));
	vector<pair<int, int>> st;
	int N, temp, day = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> park[i][j];
			if(park[i][j] > 0)
				st.push_back({i,j});
		}
	}
	
	while(st.size() > 0){
		day++;
		vector<pair<int, int>> v;
		vector<pair<int, int>> t;
		for(int i=0; i<st.size(); i++){
			int x = st[i].first;
			int y = st[i].second;
			int cnt = 0;
			
			for(int j=0; j<4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				if(nx>=0 && ny>=0 && nx<N && ny<N && park[nx][ny] == 0)
					cnt++;
			}
			
			if(park[x][y] <= cnt)
				t.push_back({i, 0});
			else{
				t.push_back({i, park[x][y] - cnt});
				v.push_back({x, y});
			}
		}
		
		for(int j=0; j<t.size(); j++){
			park[st[t[j].first].first][st[t[j].first].second] = t[j].second;
		}
		
		st = v;
	}

	cout << day;
	
	return 0;
}
