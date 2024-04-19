#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int size = sequence.size();
    vector<int> answer = {size, size*2};
    int start = 0, end = 0;
    int sum = sequence[0];
    
    while(start <= end && end < size){
        if(sum < k){
            sum += sequence[++end];
            continue;
        }
        else if(sum == k){
            if(answer[1]-answer[0] > end-start){
                answer[0] = start;
                answer[1] = end;
            }
        }
        sum -= sequence[start++];
    }
    
    return answer;
}
