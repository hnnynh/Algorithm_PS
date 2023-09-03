#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	vector<pair<long long, long long>> PC;
	int N, idx = 0;
	long long K, p, c, price = 0, sum = 0;
	bool flag = true;
	cin >> N >> K;
	
	for(int i=0; i<N; i++){
		cin >> p >> c;
		PC.push_back({c/p, p});
	}
	
	sort(PC.begin(), PC.end(), greater<>());

	while(flag){
		for(int i=0; i<PC[idx].second; i++){
			sum += PC[idx].first;
			price++;
			if(K == price){
				flag = false;
				break;
			}
		}
		idx++;
		if(idx == PC.size())
			break;
	}
	
	cout << sum << endl;
	
	return 0;
}