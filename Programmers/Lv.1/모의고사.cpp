#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> s1 = {1, 2, 3, 4, 5};
    vector<int> s2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> s3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int score1 = 0, score2 = 0, score3 = 0;
    int idx1 = 0, idx2 = 0, idx3 = 0;
    
    for(auto a:answers){
        if(a == s1[idx1++])
            score1++;
        if(a == s2[idx2++])
            score2++;
        if(a == s3[idx3++])
            score3++;
        
        if(idx1 % 5 == 0)
            idx1 = 0;
        if(idx2 % 8 == 0)
            idx2 = 0;
        if(idx3 % 10 == 0)
            idx3 = 0;
    }
    
    int max = score1 >= score2 ? score1 : score2;
    max = max >= score3 ? max : score3;
    
    if(max == score1)
        answer.push_back(1);
    if(max == score2)
        answer.push_back(2);
    if(max == score3)
        answer.push_back(3);
    
    return answer;
}
