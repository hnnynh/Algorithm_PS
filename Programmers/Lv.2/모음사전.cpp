#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int solution(string word) {
    map<char, int> m;
    
    m['A'] = 0; m['E'] = 1; m['I'] = 2; m['O'] = 3; m['U'] = 4;
    int len = word.size(), cnt = 625;
    long long ans = len;
    
    for(int i=0; i<len; i++){
        int cal = 0;
        for(int j=0; j<5-i; j++){
            cal += pow(5, j);
        }
        ans += cal * m[word[i]];
    }
    
    return ans;
}

// 625 125 25 5 1
