#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int solution(vector<int> citations) {
    int size = citations.size();
    vector<pair<int, int>> v;       // h, cnt
    
    sort(citations.begin(), citations.end());
    for(int i=citations[size-1]; i>=0; i--){
        int cnt = 0;
        for(int j=0; j<size; j++){
            if(i <= citations[j])
                cnt++;
        }
        v.push_back({i, cnt});
    }
    
    sort(v.begin(), v.end(), cmp);
        
    for(auto e:v){
        if(e.first <= e.second)
            return e.first;
    }
    
    return 0;
}
