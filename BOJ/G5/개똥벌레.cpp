#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, H, temp, cnt = 1;
    cin >> N >> H;
    vector<int> ob(H+1, 0);

    for(int i=0; i<N; i++){
        cin >> temp;
        if(i%2==0){   // 1 ~
            ob[1] += 1;
            ob[temp+1] -= 1;
        }
        else{         // H ~
            ob[H-temp+1] += 1;
        }
    }
    
    for(int i=2; i<=H; i++){
        ob[i] += ob[i-1];
    }
  
    sort(ob.begin(), ob.end());
    
    for(int i=2; i<=H; i++){
        if(ob[i] > ob[1])
            break;
        cnt++;
    }
    
    cout << ob[1] << " " << cnt;
   
	return 0;

}
