#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, int>> a;
	int N, K, ai, ac, two = 0;
	
	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> ai;
		ac = ai; two = 0;
		while(ac>0){
			if(ac%2)
				two++;
			ac /= 2;
		}
		a.push_back({two,ai});
	}
	sort(a.begin(), a.end(), greater<>());
	cout << a[K-1].second; 
	
	return 0;
}