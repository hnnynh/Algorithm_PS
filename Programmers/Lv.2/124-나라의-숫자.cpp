#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {
    string answer = "";
    int cnt = 0, cal = 1;       // cnt - 자릿수
    
    while(cal <= n){
        cnt++;
        cal += pow(3, cnt);
    }
    n -= cal - pow(3, cnt) - 1;
    cal = pow(3, cnt-1);
    
    while(cnt-->0){
        int temp = (n-1) / cal;
        switch(temp){
            case 0:
                answer += "1";
                break;
            case 1:
                answer += "2";
                break;
            case 2:
                answer += "4";
                break;
        }
        
        n -= temp * cal;
        cal /= 3;
    }
    
    return answer;
}
