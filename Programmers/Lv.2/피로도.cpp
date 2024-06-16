#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> order;
    for(int i=0; i<dungeons.size(); i++)
        order.push_back(i);
    
    do{
        int cnt = 0, t = k;
        for(auto idx:order){
            if(t >= dungeons[idx][0]){
                cnt++;
                t -= dungeons[idx][1];
            }
        }
        answer = cnt < answer ? answer : cnt;
    } while(next_permutation(order.begin(), order.end()));
    
    return answer;
}
