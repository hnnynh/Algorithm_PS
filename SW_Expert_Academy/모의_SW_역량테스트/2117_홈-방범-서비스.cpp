// queue 쓰는 BFS도 시도했음
#include<iostream>

using namespace std;
int map[21][21];
int N, M;

int calc(int k) {
    return (k * k) + (k - 1) * (k - 1);
}

int search(int r, int c){
	int ans = 0, cnt = map[r][c], range = 1;
    
    while(range <= N+1){
        if(M*cnt - calc(range) >= 0)
        	ans = cnt;
        
    	for(int i=0; i<range; i++){
            if(0 <= r-range+i && r-range+i < N && 0 <= c+i && c+i < N && map[r-range+i][c+i])
                cnt++;
        }
        for(int i=0; i<range; i++){
            if(0 <= r+i && r+i < N && 0 <= c+range-i && c+range-i < N && map[r+i][c+range-i])
                cnt++;
        }
        for(int i=0; i<range; i++){
            if(0 <= r+range-i && r+range-i < N && 0 <= c-i && c-i < N && map[r+range-i][c-i])
                cnt++;
        }
        for(int i=0; i<range; i++){
            if(0 <= r-i && r-i < N && 0 <= c-range+i && c-range+i < N && map[r-i][c-range+i])
                cnt++;
        }
        range++;
    }
	
    return ans;
}


int main(int argc, char** argv)
{	
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int answer = 0;
        cin >> N >> M;
        
        for(int i=0; i<N; i++){
        	for(int j=0; j<N; j++){
            	cin >> map[i][j];
            }
        }
		
        for(int i=0; i<N; i++){
        	for(int j=0; j<N; j++){
            	int temp = search(i, j);
                answer = answer < temp ? temp : answer;
            }
        }
        
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}
