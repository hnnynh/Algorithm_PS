#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> dp = triangle;

    
    for(int i=1; i<triangle.size(); i++){
        dp[i][0] += dp[i-1][0];
        for(int j=1; j<triangle[i].size()-1; j++){
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
        dp[i][triangle[i].size()-1] += dp[i-1][triangle[i].size()-2];
    }
    
    for(int i=0; i<dp[triangle.size()-1].size(); i++){
        if(answer < dp[triangle.size()-1][i])
            answer = dp[triangle.size()-1][i];
    }
    return answer;
}
