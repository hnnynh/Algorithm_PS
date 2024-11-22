#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    
    for(int i=0; i<want.size(); i++){
        m[want[i]] = number[i];
    }
    
    for(int i=0; i<discount.size()-9; i++){
        map<string, int> temp;
        int count = 0;
        for(int i=0; i<want.size(); i++){
            temp[want[i]] = 0;
        }
        for(int j=0; j<10; j++){
            temp[discount[i+j]]++;
        }
        for(int i=0; i<want.size(); i++){
            if(temp[want[i]] == m[want[i]])
                count++;
        }
        if(count == want.size())
            answer++;
    }
    
    return answer;
}
