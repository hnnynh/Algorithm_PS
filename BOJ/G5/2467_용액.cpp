#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, left, right, val = 2000000000, ansl = 0, ansr = 0;
	vector<int> v(100000, 0);
	cin >> N;
    
    left = 0;
    right = N - 1;
    
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    
    while(left < right){
        int sum = v[left] + v[right];
        
        if(abs(sum) < abs(val)){
            val = sum;
            ansl = left;
            ansr = right;
        }
        
        if(sum == 0)
            break;
        if(sum < 0)
            left++;
        else
            right--;
    }
    
    cout << v[ansl] << " " << v[ansr];
    
	return 0;

}
