#include <string>
#include <vector>

using namespace std;

vector<int> num;
int answer = 0;

void dfs(int idx, int val, int target){
    if(idx == num.size()){
        if(val == target)
            answer++;
        return;
    }
    
    dfs(idx+1, val+num[idx], target);
    dfs(idx+1, val-num[idx], target);
}

int solution(vector<int> numbers, int target) {

    num = numbers;
    dfs(0, 0, target);    
    
    return answer;
}
