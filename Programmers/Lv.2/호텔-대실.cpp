#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<string> a, vector<string> b){
    return a[1] > b[1];
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    sort(book_time.begin(), book_time.end(), cmp);
    priority_queue<string> pq;
    pq.push(book_time[0][0]);
    
    for(int i=1; i<book_time.size(); i++){
        string f = pq.top();

        int h1 = stoi(f.substr(0, 2));
        int m1 = stoi(f.substr(3, 2));
        int h2 = stoi(book_time[i][1].substr(0, 2));
        int m2 = stoi(book_time[i][1].substr(3, 2));
        int diff = (h1 - h2) * 60 + m1 - m2;
        
        pq.push(book_time[i][0]);
        if(diff < 10)
            answer = pq.size();
        else
            pq.pop();
    }
    
    return answer;
}
