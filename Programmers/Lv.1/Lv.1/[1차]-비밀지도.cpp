#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        int s1[n], s2[n], cnt = 1;
        int n1 = arr1[i], n2 = arr2[i];
        string line = "";
        
        for(int j=0; j<n; j++){
            if(n1%2)
                s1[n-1-j] = 1;
            else
                s1[n-1-j] = 0;
            n1 /= 2;
            
            if(n2%2)
                s2[n-1-j] = 1;
            else
                s2[n-1-j] = 0;
            n2 /= 2;
        }
        
        for(int j=0; j<n; j++){
            if(s1[j] || s2[j])
                line += "#";
            else
                line += " ";
        }
        answer.push_back(line);
    }
    
    return answer;
}