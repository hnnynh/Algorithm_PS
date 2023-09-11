#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100001] = {false,};
vector<long long> edge[100001];
vector<pair<double, vector<long long>>> result;		// 밀도, 컴포넌트
long long N;

bool cmp(pair<double, vector<long long>> a, pair<double, vector<long long>> b){
	if(a.first == b.first){
		if(a.second.size() == b.second.size())
			return a.second[0] < b.second[0];
		return a.second.size() < b.second.size();
	}
	return a.first > b.first;
}

void trav(long long c){
	long long sum = 0;
	vector<long long> temp;
	queue<long long> q;
	q.push(c);
	
	while(!q.empty()){
		long long com = q.front();
		q.pop();
		if(visited[com])
			continue;
		visited[com] = true;
		temp.push_back(com);
		sum += edge[com].size();
		
		for(int i=0; i<edge[com].size(); i++){
			if(visited[edge[com][i]])
				continue;
			q.push(edge[com][i]);
		}
	}
	sort(temp.begin(), temp.end());
	
	result.push_back({(double)sum/(temp.size()*2), temp});
}

int main() {

	int M, a, b;
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for(int i=1; i<=N; i++){
		if(visited[i])
			continue;
		trav(i);
	}
	
	sort(result.begin(), result.end(), cmp);
	for(int i=0; i<result[0].second.size(); i++){
		cout << result[0].second[i] << ' ';
	}
	
	return 0;
}