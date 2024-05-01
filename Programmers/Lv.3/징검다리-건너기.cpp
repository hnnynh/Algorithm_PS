#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    vector<int> v;
    int min = 200000000, max = 0, mid;
    
    if(stones.size() == 1)
        return stones[0];
    
    for(int i=0; i<stones.size(); i++){
        min = stones[i] < min ? stones[i] : min;
        max = stones[i] > max ? stones[i] : max;
    } 
    
    if(stones.size() == k)
        return max;
    
    while(max >= min){
        int cnt = 0, m = 0;
        mid = (max+min)/2;
        for(int i=0; i<stones.size(); i++){
            if(stones[i] - mid <= 0)
                cnt++;
            else
                cnt = 0;
            if(cnt > m)
                m = cnt;
        }
        if(m >= k){
            max = mid - 1;
            v.push_back(mid);
        }
        else
            min = mid + 1;
    }
    sort(v.begin(), v.end());
    
    return v[0];
}
