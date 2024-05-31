#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> apeach;
vector<vector<int>> cases;

bool cmp(vector<int> a, vector<int> b){
    if(a[11] == b[11]){
        for(int i=10; i>=0; i--){
            if(a[i] != b[i])
                return a[i] > b[i];
        }
    }
    return a[11] > b[11];
}

void dfs(vector<int> st, int idx, int arrL, int scoreR, int scoreA){
    if(arrL < 0)
        return;
    if(idx == 10){
        if(scoreR > scoreA){
            st.push_back(arrL);
            st.push_back(scoreR-scoreA);
            cases.push_back(st);
        }
        return;
    }
    
    st.push_back(0);
    if(apeach[idx] > 0)
        dfs(st, idx+1, arrL, scoreR, scoreA+10-idx);
    else
        dfs(st, idx+1, arrL, scoreR, scoreA);
    
    st[idx] = apeach[idx]+1;
    dfs(st, idx+1, arrL-apeach[idx]-1, scoreR+(10-idx), scoreA);
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    apeach = info;
    
    dfs({}, 0, n, 0, 0);
    
    if(cases.empty())
        answer.push_back(-1);
    else{
        sort(cases.begin(), cases.end(), cmp);
        for(int i=0; i<11; i++)
            answer.push_back(cases[0][i]);
    }
    
    return answer;
}
