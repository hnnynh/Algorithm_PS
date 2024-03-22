#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<int> line(n, 1); 
    vector<vector<int>> map(m, line);
    
    for(int i=0; i<puddles.size(); i++){
        map[puddles[i][0]-1][puddles[i][1]-1] = 0;
    }
    
    for(int i=1; i<m; i++){
        if(map[i-1][0] < 1)
            map[i][0] = 0;
    }
    for(int i=1; i<n; i++){
        if(map[0][i-1] < 1)
            map[0][i] = 0;
    }
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(map[i][j] < 1)
                continue;
            map[i][j] = (map[i-1][j] + map[i][j-1]) % 1000000007;
        }
    }
    
    return map[m-1][n-1];
}
