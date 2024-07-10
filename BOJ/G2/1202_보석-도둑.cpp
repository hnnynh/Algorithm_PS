#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

    vector<pair<int, int>> dia;
    vector<int> bag;
    priority_queue<int> pq;
	int N, K, M, V, C, idx = 0;
	long long answer = 0;
	
    cin >> N >> K;
    
    for(int i=0; i<N; i++){
        cin >> M >> V;
        dia.push_back({M, V});      // 무게 / 가격
    }
    
    for(int i=0; i<K; i++){
        cin >> C;
        bag.push_back(C);
    }

    sort(dia.begin(), dia.end());
    sort(bag.begin(), bag.end());
    
    for(int i=0; i<K; i++){
        while(idx < N && bag[i] >= dia[idx].first){
            pq.push(dia[idx++].second);
        }
        
        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    
    cout << answer;

	return 0;
}
