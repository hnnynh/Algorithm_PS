#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[1001];
int N, M, S, E;

int BFS(int no){
	if(no == S || no == E)
		return -1;
	
	vector<int> dist(1001, 1001);
	queue<int> q;
	
	dist[S] = 1;
	q.push(S);
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		for(int i=0; i<edge[cur].size(); i++){
			if(no == edge[cur][i] || dist[edge[cur][i]] < dist[cur] + 1)	// 방문할 수 없거나 이미 짧은 경로가 존재
				continue;
			dist[edge[cur][i]] = dist[cur] + 1;
			q.push(edge[cur][i]);
		}
	}
	
	if(dist[E] >= 1001)
		return -1;
	return dist[E];	
}

int main() {
	int a, b;
	cin >> N >> M >> S >> E;
	
	for(int i=0; i<M; i++){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for(int i=1; i<=N; i++){
		cout << BFS(i) << endl;
	}
	
	return 0;
}