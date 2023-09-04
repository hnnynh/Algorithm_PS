#include <iostream>
#include <vector>

using namespace std;

int ans = 0, N;
bool edge[2002][2002] = {false,};
bool visited[2002] = {false,};

void trav(int node){
	visited[node] = true;

	for(int i=1; i<=N; i++){
		if(edge[node][i] && edge[i][node])
			if(!visited[i])
				trav(i);
	}
}

int main() {
	
	int M, a, b;
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		cin >> a >> b;
		edge[a][b] = true;
	}
	
	for(int i=1; i<=N; i++){
		if(visited[i])
			continue;
		ans++;
		trav(i);	// traversal -> 연합 개수 찾기
	}
	
	cout << ans << endl;
	
	return 0;
}

// Fail이 재귀 때문인줄 알았는데 trav() 내부 인덱스 문제였다.
// queue로도 구현 가능할 듯