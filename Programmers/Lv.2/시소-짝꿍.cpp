#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, long long> m;
    
    sort(weights.begin(), weights.end());
    
    for(int i=0; i<weights.size(); i++){
        m[weights[i]] = 0;
    }
    for(int i=0; i<weights.size(); i++){
        m[weights[i]]++;
    }
    
    for(int i=0; i<weights.size(); i++){
        if(weights[i] > 1)
            answer += m[weights[i]] * (m[weights[i]] - 1) / 2;
        i += m[weights[i]] - 1;
    }
    
    for(int i=0; i<weights.size(); i++){
        for(int j=i+m[weights[i]]; j<weights.size(); j++){
            if(weights[i] == 2*weights[j] || 2*weights[i] == weights[j] || 3*weights[i] == 4*weights[j] || 4*weights[i] == 3*weights[j] || 2*weights[i] == 3*weights[j] || 3*weights[i] == 2*weights[j])
                answer += m[weights[i]] * m[weights[j]];
            j += m[weights[j]] - 1;
        }
        i += m[weights[i]] - 1;
    }
    
    return answer;
}
