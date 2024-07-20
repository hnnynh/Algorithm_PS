#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int H, W, answer = 0;
	vector<int> block(500, 0);
	cin >> H >> W;
	for(int i=0; i<W; i++){
	    cin >> block[i];
	}
	
	int left = 0, right = W - 1;
	int ml = block[left], mr = block[right];
	
	while(left < right){
	    if(ml < block[left])
	        ml = block[left];
	    if(mr < block[right])
	        mr = block[right];
	    
	    if(ml <= mr){
	        answer += ml - block[left];
	        left++;
	    }
	    else{
	        answer += mr - block[right];
	        right--;
	    }
	}
	
	cout << answer;
    
	return 0;

}
