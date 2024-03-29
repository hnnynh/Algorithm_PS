#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    stack<pair<int, int>> st;
    vector<int> answer(prices.size(), 0);
    
    st.push({prices[0], 0});
    for(int i=1; i<prices.size(); i++){
        if(st.top().first > prices[i]){
            while(!st.empty() && st.top().first > prices[i]){
                pair<int, int> p = st.top();
                st.pop();
                answer[p.second] = i - p.second;   
            }  
        }
        st.push({prices[i], i});
    }
    
    while(!st.empty()){
        pair<int, int> p = st.top();
        st.pop();
        answer[p.second] = prices.size() - 1 - p.second;   
    }  
    
    return answer;
}
