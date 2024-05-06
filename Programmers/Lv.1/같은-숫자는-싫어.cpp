#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    for(auto a:arr){
        if(st.empty()){
            st.push(a);
            answer.push_back(a);
        }
        else{
            int cur = st.top();
            if(cur == a)
                continue;
            else{
                st.pop();
                st.push(a);
                answer.push_back(a);
            }
        }
    }

    return answer;
}
