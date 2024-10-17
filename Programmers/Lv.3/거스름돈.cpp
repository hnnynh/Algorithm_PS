#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    
    for(auto c:money){
        for(int i=c; i<n+1; i++){
            dp[i] += dp[i-c];
        }
    }
    
    return dp[n] % 1000000007;
}
// i-c에서 동전 c를 더하면 i가 됨 -> i-c를 만들 수 있는 경우의 수를 i에 추가
