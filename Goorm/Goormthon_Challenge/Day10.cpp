#include <iostream>
#include <string>

using namespace std;

pair<int, char> board[201][201];
int N;
int dy[4] = {0, 0, 1, -1};  // R L D U
int dx[4] = {1, -1, 0, 0};

int play(int y, int x){
	int score = 0, dir;
	bool flag = false;
	bool visited[201][201] = {false, };
	
	while(true){
		if(flag)
			break;
		
		int cnt = board[y][x].first;
		switch(board[y][x].second){
			case 'R': dir = 0;
				break;
			case 'L': dir = 1;
				break;
			case 'D': dir = 2;
				break;
			case 'U': dir = 3;
				break;
		}
		
		while(cnt--){
			if(visited[y][x]){
				flag = true;
				break;
			}
			visited[y][x] = true;	
			y += dy[dir];
			if(y <= 0)
				y += N;
			else if(y > N)
				y -= N;
			
			x += dx[dir];
			if(x <= 0)
				x += N;
			else if(x > N)
				x -= N;
			
			score++;
		}	
	}
	
	return score;
}


int main() {
	
	int tempi;
	char tempc;
	int g1, g2, p1, p2;
	cin >> N >> g1 >> g2 >> p1 >> p2;
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> tempi >> tempc;
			board[i][j] = {tempi, tempc};
		}
	}
	
	int goorm = play(g1, g2);
	int player = play(p1, p2);
	
	if(goorm > player)
		cout << "goorm " << goorm << endl; 
	else 
		cout << "player " << player << endl;

	return 0;
}