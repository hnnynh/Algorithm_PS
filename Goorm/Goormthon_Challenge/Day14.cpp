#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> node[2001];
	vector<bool> visited(2001, 0);
	int N, M, K, s, e;
	cin >> N >> M >> K;
	
	for(int i=0; i<M; i++){
		cin >> s >> e;
		node[s].push_back(e);
		node[e].push_back(s);
	}
	
	int now = K, ans = 0;
	visited[now] = true;
	while(true){
		int next = 1e9;
		ans++;
		for(int i=0; i<node[now].size(); i++){
			if(visited[node[now][i]])
				continue;
			if(node[now][i] < next)
				next = node[now][i];
		}
		if(next == 1e9)
			break;
		now = next;
		visited[now] = true;
	}
	
	cout << ans << ' ' << now << endl;
	
	return 0;
}