#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> clear(N+2, 0), fail(N+2, 0);
    vector<pair<double, int>> rate;
    
    for(int i=0; i<stages.size(); i++){
        for(int j=1; j<=stages[i]; j++){
            clear[j]++;
        }
        fail[stages[i]]++;
    }
    
    for(int i=1; i<=N; i++){
        if(clear[i] == 0)
            rate.push_back({0, i});
        else
            rate.push_back({(double)fail[i]/clear[i], i});
    }
    
    sort(rate.begin(), rate.end(), cmp);
    
    for(int i=0; i<N; i++){
        answer.push_back(rate[i].second);
    }
              
    return answer;
}