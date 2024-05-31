#include<iostream>

using namespace std;

int V, E;
bool g[1001][1001] = { {false,}, };
bool visited[1001] = { false, };

void DFS(int v){
    if(visited[v])
        return;
    
    for(int i=1; i<=V; i++){
        if(!visited[i] && g[i][v])
            return;         
    }
    visited[v] = true;
    cout << v << " ";
    
    for(int i=1; i<=V; i++){
    	if(!visited[i] && g[v][i])
            DFS(i);
    }
}

int main(int argc, char** argv)
{
    for(int test_case=1; test_case<=10; ++test_case){
    	int f, t;
        cin >> V >> E;
        for(int i=1; i<=V; i++){
            visited[i] = false;
        	for(int j=1; j<=V; j++){
            	g[i][j] = false;
            }
        }
        
        for(int i=0; i<E; i++){
        	cin >> f >> t;
            g[f][t] = true;
        }
        
        cout << "#" << test_case << " ";
        for(int i=1; i<=V; i++){
        	if(!visited[i])
                DFS(i);
        }
        cout << endl;
    }
	return 0;
}
