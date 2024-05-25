#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<int> r(n+1, 1000001);
    vector<vector<int>> v(n+1, r);
    
    for(auto f:fares){
        v[f[0]][f[1]] = f[2];
        v[f[1]][f[0]] = f[2];
    }
    for(int i=1; i<=n; i++){
        v[i][i] = 0;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                v[j][k] = min(v[j][k], v[j][i]+v[i][k]);
            }
        }
    }
    answer = v[s][a] + v[s][b];
    
    for(int i=1; i<=n; i++){
        answer = min(answer, v[s][i]+v[i][a]+v[i][b]);
    }
    
    return answer;
}
