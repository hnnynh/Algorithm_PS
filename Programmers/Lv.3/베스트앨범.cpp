#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> idx;
    map<string, bool> check;
    vector<pair<int, int>> row;
    vector<pair<int, int>> sum;
    vector<vector<pair<int, int>>> v;
    int cnt = 0;
    
    for(int i=0; i<genres.size(); i++){
        check[genres[i]] = false;
        v.push_back(row);
    }
    
    for(int i=0; i<genres.size(); i++){
        if(!check[genres[i]]){
            idx[genres[i]] = cnt;
            sum.push_back({0, cnt++});
        }
        check[genres[i]] = true;
    }
    
    for(int i=0; i<genres.size(); i++){
        v[idx[genres[i]]].push_back({plays[i], i});
        sum[idx[genres[i]]].first += plays[i];
    }
    
    sort(sum.begin(), sum.end(), greater<>());
    for(int i=0; i<sum.size(); i++){
        sort(v[i].begin(), v[i].end(), cmp);
    }
    
    for(auto s:sum){
        answer.push_back(v[s.second][0].second);
        if(v[s.second].size() == 1)
            continue;
        answer.push_back(v[s.second][1].second);
    }
    
    return answer;
}
