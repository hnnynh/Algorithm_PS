#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, M, a, b, k;
    cin >> N >> M;
    vector<int> y(N+1, 0);
    vector<int> temp(N+1, 0);

    for(int i=1; i<=N; i++)
        cin >> y[i];
    
    for(int i=0; i<M; i++){
        cin >> a >> b >> k;
        temp[a] += k;
        temp[b+1] -= k;
    }
    
    for(int i=2; i<=N; i++){
        temp[i] += temp[i-1];
    }
    
    for(int i=1; i<=N; i++){
        cout << y[i] + temp[i] << " ";
    }

	return 0;

}