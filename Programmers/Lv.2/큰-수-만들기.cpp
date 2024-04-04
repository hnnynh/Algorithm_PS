#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int st = 0, cnt = 0, k1 = k;
    
    while(k > 0){
        int max = -1;
        
        for(int i=0; i<k+1; i++){
            if(max < number[st+i] - '0'){
                max = number[st+i] - '0';
                cnt = i;
            } 
        }
        
        answer += number[st+cnt];
        k -= cnt;
        st += cnt + 1;
        cnt = 0;
    }
    
    if(answer.size() < number.size()){
        for(int i=st; i<number.size(); i++){
            answer += number[i];
        }
        return answer;
    }
    else{                   // 마지막 k개를 빼는 경우 고려
        string last = "";
        for(int i=0; i<number.size()-k1; i++){
            last += number[i];
        }
        return last;
    }
}
