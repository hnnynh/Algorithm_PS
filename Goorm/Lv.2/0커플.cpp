#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	
	int N, S, sum = 0;
	vector<int> p(200001, 0);
	vector<int> num;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> S;
		num.push_back(abs(S));
		if(S > 0)
			p[S] += 1;
		else
			p[S*-1] -= 1;
	}
	
	for(int i=0; i<N; i++){
		if(p[num[i]] > 0)
			sum += num[i];
		else if(p[num[i]] < 0)
			sum -= num[i];
	}
	
	cout << sum;
	
	return 0;
}
