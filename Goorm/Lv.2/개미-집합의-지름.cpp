#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int N, D, temp, start = 0, end = 0, answer = 0;
	vector<int> v;
	cin >> N >> D;
	for(int i=0; i<N; i++){
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	
	while(start <= end && end < N){
		if(v[end]-v[start] <= D)
			end++;
		else
			start++;
		
		answer = answer < end-start ? end-start : answer;
	}
	
	cout << N-answer;
	
	return 0;
}
