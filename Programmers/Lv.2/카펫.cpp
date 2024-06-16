#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int mul = brown + yellow;
    int v, h;       // v > h
    
    for(int i=2; i<mul/2; i++){
        if(mul % i == 0){
            h = i;
            v = mul / i;
            if(2*v+2*h-4 == brown){
                answer.push_back(v);
                answer.push_back(h);
                break;
            }
        }
    }
    
    return answer;
}
