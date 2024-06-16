#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    set<string> s;
    
    for(int i=0; i<clothes.size(); i++){
        s.insert(clothes[i][1]);
        m[clothes[i][1]] = 0;
    }
    
    for(int i=0; i<clothes.size(); i++){
        m[clothes[i][1]]++;
    }
    
    for(auto it=s.begin(); it != s.end(); it++){
        answer *= m[*it] + 1;
    }
    
    return answer - 1;
}
