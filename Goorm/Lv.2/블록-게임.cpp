#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int main() {
	int N, x = 0, y = 0, temp, score = 1;
	string D;
	vector<int> scores;
	map<pair<int, int>, bool> visited;
	stack<pair<int, int>> st;
	stack<int> s;
	
	cin >> N >> D;
	for(int i=0; i<N; i++){
		cin >> temp;
		scores.push_back(temp);
	}
	
	st.push({x, y});
	s.push(1);
	visited[{x, y}] = true;
	for(int i=0; i<D.size(); i++){
		if(D[i] == 'L')
			x -= 1;
		else if(D[i] == 'R')
			x += 1;
		else if(D[i] == 'U')
			y += 1;
		else
			y -= 1;
		
		if(visited[{x, y}]){
			int idx = i;
			while(true){
				int sx = st.top().first;
				int sy = st.top().second;
				score -= s.top();
				
				st.pop();
				s.pop();
				visited[{sx, sy}] = false;
				if(sx == x && sy == y){
					break;
				}
			}
		}
		st.push({x, y});
		s.push(scores[i]);
		visited[{x, y}] = true;
		score += scores[i];
	}
	
	cout << score;
	
	return 0;
}
