#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> pqp, pqm;
    int s = 0;
    
    for(int i=0; i<operations.size(); i++){
        string op;
        int num;
        stringstream ss(operations[i]);
        ss >> op >> num;
        if(op == "I"){
            pqp.push(num);
            pqm.push(num*-1);
            s++;
        }
        else{
            if(s == 0)
                continue;
            if(num > 0)
                pqp.pop();
            else
                pqm.pop();
            s--;
        }
    }
    
    vector<int> ans, res;
    for(int i=0; i<s; i++){
        ans.push_back(pqp.top());
        pqp.pop();
    }
    
    if(s==0){
        res.push_back(0);
        res.push_back(0);
    }
    else{
        res.push_back(ans[0]);
        res.push_back(ans[s-1]);
    }
    
    return res;
}
