#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0, idx = 0, cur = 0;
    queue<string> q[2];
    map<string, bool> m;
    
    if(cacheSize == 0)
        return cities.size() * 5;
    
    for(auto c:cities){
        
        for(int i=0; i<c.length(); i++){
            if ('A' <= c[i] && c[i] <= 'Z')
                c[i] += 'a' - 'A';
        }
        
        if(m.find(c) != m.end()){
            if(m[c]){
                int next;
                if(cur == 1)
                    next = 0;
                else
                    next = 1;
                
                while(!q[cur].empty()){
                    string temp = q[cur].front();
                    q[cur].pop();
                    if(temp == c)
                        continue;
                    q[next].push(temp);
                }
                q[next].push(c);
                cur = next;
                answer++;
            }
            else {
                string temp = q[cur].front();
                q[cur].pop();
                m[temp] = false;
                q[cur].push(c);
                m[c] = true;
                answer += 5;
            }
        }
        else{
            q[cur].push(c);
            m[c] = true;
            answer += 5;
        }

        while(q[cur].size() > cacheSize){
            string temp = q[cur].front();
            q[cur].pop();
            m[temp] = false;
        }        
    }
   
    return answer;
}