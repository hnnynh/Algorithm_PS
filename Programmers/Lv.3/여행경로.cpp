#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<vector<string>> temp;
vector<bool> visited(10001, false);
bool isEnd = false;

bool cmp(vector<string> a, vector<string> b){
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

void dfs(string depart){
    answer.push_back(depart);
    if(answer.size() == temp.size() + 1){
        isEnd = true;
        return;
    }
    
    for(int i=0; i<temp.size(); i++){
        if(temp[i][0] == depart && !visited[i]){
            visited[i] = true;
            dfs(temp[i][1]);
            if (isEnd)
                return;
            visited[i] = false;
        }
    }
    answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), cmp);
    temp = tickets;
    dfs("ICN");
    
    return answer;
}
