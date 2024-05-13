#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

bool check(int num){
    if(num <= 1)
        return false;
    
    for(int i=2; i<=sqrt(num); i++){
        if(num%i==0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> nums;
    
    sort(numbers.begin(), numbers.end());
    
    do{
        string str = "";
        for(int i=0; i<numbers.size(); i++){
            str += numbers[i];
            int n = stoi(str);
            if(check(n))
                nums.insert(n);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return nums.size();
}
