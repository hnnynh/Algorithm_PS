#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map <char, int> t;
    
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 7));
    int day = stoi(today.substr(8, 10));
    
    for(int i=0; i<terms.size(); i++){
        if(terms[i].length() == 3)
            t[terms[i][0]] = terms[i][2] - '0';
        else
            t[terms[i][0]] = stoi(terms[i].substr(2, 3));
    }
    
    for(int i=0; i<privacies.size(); i++){
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 7));
        int d = stoi(privacies[i].substr(8, 10));
        int period = t[privacies[i][11]];
        int periodY = period / 12;
        int periodM = period % 12;
        
        y += periodY;
        m += periodM;
        d--;
        
        if(d==0){
            d = 28;
            m--;
        }
        if(m > 12){
            m -= 12;
            y++;
        }

        if((y < year) || (y == year && m < month) || (y == year && m == month && d < day))
            answer.push_back(i+1);     
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;        
}