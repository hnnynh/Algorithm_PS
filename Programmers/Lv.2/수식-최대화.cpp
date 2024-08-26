#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long calculation(long long num1, long long num2, char op){
    if(op == '+')
        return num1 + num2;
    else if(op == '-')
        return num1 - num2;
    else
        return num1 * num2;
}

long long solution(string expression) {
    long long answer = 0;
    string temp = "";
    
    vector<char> op;
    vector<int> num;
    vector<char> pri = {'*', '+', '-'};

    for(auto c:expression){
        if(c == '+' || c == '-' || c == '*'){
            op.push_back(c);
            num.push_back(stoi(temp));
            temp = "";
        }
        else{
            temp += c;
        }
    }
    num.push_back(stoi(temp));

    do{
        long long t;
        deque<long long> dq;
        vector<char> opv;
        deque<long long> dq2;
        
        dq.push_back(num[0]);
        for(int i=0; i<op.size(); i++){
            if(op[i] == pri[0]){
                long long lt = calculation(dq.back(), num[i+1], pri[0]);
                dq.pop_back();
                dq.push_back(lt);
            }
            else{
                dq.push_back(num[i+1]);
                opv.push_back(op[i]);
            }
        }
        
        dq2.push_back(dq.front());
        for(int i=0; i<opv.size(); i++){
            if(opv[i] == pri[1]){
                long long lt = calculation(dq2.back(), dq[i+1], pri[1]);
                dq2.pop_back();
                dq2.push_back(lt);
            }
            else{
                dq2.push_back(dq[i+1]);
            }
        }
        
        t = dq2.front();
        for(int i=1; i<dq2.size(); i++){
            t = calculation(t, dq2[i], pri[2]);
        }
        
        if(t < 0)
            t *= -1;
        answer = t < answer ? answer : t;
        
    } while(next_permutation(pri.begin(), pri.end()));
    
    return answer;
}
