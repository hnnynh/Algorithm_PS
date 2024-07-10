#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N;
    vector<int> v(100000, 0);
	cin >> N;
	v[0] = 1;
	v[1] = 3;
	
	for(int i=2; i<=N; i++){
	    v[i] = (v[i-1] * 2 + v[i-2]) % 9901;
	}

	cout << v[N] ;
   
	return 0;

}
