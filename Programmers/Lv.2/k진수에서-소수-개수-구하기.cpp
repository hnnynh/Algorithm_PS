#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long num){
    if(num == 1 || num == 0)
        return false;
    
    for(int i=2; i<=sqrt(num); i++){
        if(num%i==0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int> v;
    string num = "";
    long long temp = 0;
    
    while(n > 0){
        v.push_back(n%k);
        n/=k;
    }

    for(int i=v.size()-1; i>=0; i--){
        num += v[i] + '0';
    }
    
    for(int i=0; i<num.length(); i++){
        if(num[i] == '0'){
            if(isPrime(temp)){
                answer++;
            }
            temp = 0;
            continue;
        }
        temp *= 10;
        temp += num[i] - '0';
    }
    
    if(isPrime(temp)){
        answer++;
    }

    return answer;
}