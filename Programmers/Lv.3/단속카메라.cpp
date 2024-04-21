#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0, temp = -30000;
    sort(routes.begin(), routes.end());
    
    for(auto r:routes){
        if(r[0] > temp){
            answer++;
            temp = r[1];
        }
        if(r[1] < temp)
            temp = r[1];
    }

    return answer;
}
