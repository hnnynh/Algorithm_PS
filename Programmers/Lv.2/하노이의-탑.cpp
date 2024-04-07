#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void hanoi(int n, int start, int mid, int end){
    vector<int> inner;
    if(n == 1){
        inner.push_back(start);
        inner.push_back(end);
        answer.push_back(inner);
    }
    else{
        hanoi(n-1, start, end, mid);
        inner.push_back(start);
        inner.push_back(end);
        answer.push_back(inner);
        hanoi(n-1, mid, start, end);
    }
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);  
    return answer;
}
