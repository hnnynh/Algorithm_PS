// 구현

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> store;
    map<string, int> m;
    m.insert({"zero", 0});
    m.insert({"one", 1});
    m.insert({"two", 2});
    m.insert({"three", 3});
    m.insert({"four", 4});
    m.insert({"five", 5});
    m.insert({"six", 6});
    m.insert({"seven", 7});
    m.insert({"eight", 8});
    m.insert({"nine", 9});
    
    string in;
    
    for(int i=0; i<s.length(); i++){
        if('0' <= s[i] && s[i] <= '9')
            store.push_back(s[i]-'0');
        else
            in += s[i];
        
        if(m.find(in) != m.end()){
            store.push_back(m.find(in)->second);
            in = "";
        }
    }
    
    for(int i=0; i<store.size(); i++){
        answer += store[i];
        answer *= 10;
    }
    answer /= 10;
    
    return answer;
}