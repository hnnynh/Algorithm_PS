#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>

using namespace std;

vector<vector<int>> s;
vector<pair<int, int>> p;

int dfs(int cnt, vector<int> st1, vector<int> st2){
	if(cnt==p.size()){
        int time = 0;
    	queue<int> q1, q2;
        priority_queue<int> pq1, pq2;
        
        for(int i=0; i<st1.size(); i++){
            int dis = abs(s[0][0]-p[st1[i]].first) + abs(s[0][1]-p[st1[i]].second) + 1;
            pq1.push(dis*-1);
        }
        for(int i=0; i<st2.size(); i++){
            int dis = abs(s[1][0]-p[st2[i]].first) + abs(s[1][1]-p[st2[i]].second) + 1;
            pq2.push(dis*-1);
        }
        
        while(true){
            if(pq1.empty() && pq2.empty())
                break;
            time++;
            
            if(!pq1.empty()){
                int next = pq1.top()*-1;
                while(!q1.empty() && q1.front()+s[0][2] <= time)
                    q1.pop();
                
                while(q1.size()<3 && next <= time){
                	q1.push(time);
                    pq1.pop();
                    if(!pq1.empty())
                        next = pq1.top()*-1;
                    else
                        break;
                }
            }
            if(!pq2.empty()){
                int next = pq2.top()*-1;
                while(!q2.empty() && q2.front()+s[1][2] <= time)
         			q2.pop();
            	
                while(q2.size()<3 && next <= time){
                	q2.push(time);
                    pq2.pop();
                    if(!pq2.empty())
                        next = pq2.top()*-1;
                    else
                        break;
                }
            }
        }
        int l1 = 0, l2 = 0;
        while(!q1.empty()){
            l1 = q1.front();
            q1.pop();
        }
        while(!q2.empty()){
            l2 = q2.front();
            q2.pop();
        }
        time = l1+s[0][2] < l2+s[1][2] ? l2+s[1][2] : l1+s[0][2];
        return time;
    }
    else{
        st1.push_back(cnt);
    	int d1 = dfs(cnt+1, st1, st2);
        st1.pop_back();
        st2.push_back(cnt);
        int d2 = dfs(cnt+1, st1, st2);
        st2.pop_back();
        return d1 < d2 ? d1 : d2;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, temp;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<vector<int>> stairs;
        vector<pair<int, int>> people;
		cin >> N;
        for(int i=0; i<N; i++){
        	for(int j=0; j<N; j++){
            	cin >> temp;
                if(temp == 1)
                    people.push_back({i, j});
                if(temp > 1)
                	stairs.push_back({i, j, temp});
            }
        }
        s = stairs;		p = people;
        
        cout << "#" << test_case << " " << dfs(0, {}, {}) << endl;
	}
	return 0;
}
