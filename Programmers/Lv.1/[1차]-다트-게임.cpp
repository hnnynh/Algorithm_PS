#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int cur = 0, prev = 0;
    
    for(int i=0; i<dartResult.length(); i++){
        if(dartResult[i] == 'S'){
            answer += cur;
        }
        else if(dartResult[i] == 'D'){
            cur = cur * cur;
            answer += cur;
        }
        else if(dartResult[i] == 'T'){
            cur = cur * cur * cur;
            answer += cur;
        }
        else if(dartResult[i] == '#'){
            answer -= cur * 2;
            cur *= -1;
        }
        else if(dartResult[i] == '*'){
            answer += prev + cur;
            prev *= 2;
            cur *= 2;
        }
        if('0' <= dartResult[i] && dartResult[i] <= '9'){
            prev = cur;
            cur = dartResult[i] - '0';
            if(i<dartResult.length()-1 && dartResult[i] == '1'){
                if(dartResult[i+1] == '0'){
                    cur = 10;
                    i++;
                }     
            }
        }
    }
    
    return answer;
}