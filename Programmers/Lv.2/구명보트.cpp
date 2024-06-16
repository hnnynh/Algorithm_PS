#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, idx = people.size()-1;
    vector<bool> r(people.size(), false);
    sort(people.begin(), people.end(), greater<int>());
    
    for(int i=0; i<people.size(); i++){
        if(r[i])
            break;
        answer++;
        int w = people[i];
        r[i] = true;
        
        if(!r[idx] && w+people[idx] <= limit){
            r[idx] = true;
            w += people[idx];
            idx--;
        }
    }
    
    return answer;
}
