#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    long long nn = 1, ki = k, ni = n-1;         // long long 효율성 테스트 주의
    vector<bool> use(n, false);
    vector<int> answer;
    
    for(int i=1; i<=n-1; i++){
        nn *= i;
    }
    
    while(ni > 0){
        long long next = (ki-1) % nn;
        long long ans = (ki-1) / nn;
        int cnt = -1;

        for(int i=0; i<use.size(); i++){          // ans 번째 사용하지 않은 수 선택
            if(!use[i])
                cnt++;  
            if(cnt == ans){
                use[i] = true;
                answer.push_back(i+1);
                break;
            }
        }
        nn /= ni--;
        ki = next+1;
    }
    
    for(int i=0; i<use.size(); i++){
        if(!use[i]){
            answer.push_back(i+1);
            break;
        }     
    }

    return answer;
}
