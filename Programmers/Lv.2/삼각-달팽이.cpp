#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer(n*(n+1)/2, 0);
    int jump = 0, cur = 0, num = 1;
    bool isR = true;
    
    //   -> <- 패턴 찾기
    while(n-->0){
        if(isR){
            for(int i=0; i<n+1; i++){
                answer[cur+jump] = num++;
                cur += jump;
                jump++;
            }
            n--;
            for(int i=0; i<n+1; i++){
                answer[++cur] = num++;
            }
            isR = false;
        }    
        else{
            for(int i=0; i<n+1; i++){
                answer[cur-jump] = num++;
                cur -= jump;
                jump--;
            }
            isR = true;
        }
    }
    
    return answer;
}
