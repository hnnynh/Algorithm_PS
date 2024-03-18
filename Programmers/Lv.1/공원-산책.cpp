#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    vector<int> row(park[0].size(), 0);
    vector<vector<int>> p(park.size(), row);
    int si, sj;
    
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[i].size(); j++){
            switch(park[i][j]){
                case 'S':
                    si = i;
                    sj = j;
                    break;
                case 'O':
                    park[i][j] = 1;
                    break;
                case 'X':
                    park[i][j] = 0;
                    break;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++){
        string dir, diss;
        stringstream ss(routes[i]);
        ss >> dir >> diss;
        int dis = stoi(diss);
        bool flag = false;
        int fi = si, fj = sj;
        
        for(int i=0; i<dis; i++){
            if(dir == "E"){
                if(sj+1 >= park[0].size() || park[si][sj+1] == 0){
                    flag = true;
                    break;
                }
                sj++;
            }
            else if(dir == "W"){
                if(sj-1 < 0 || park[si][sj-1] == 0){
                    flag = true;
                    break;
                }
                sj--;
            }
            else if(dir == "N"){
                if(si-1 < 0 || park[si-1][sj] == 0){
                    flag = true;
                    break;
                }
                si--;
            }
            else if(dir == "S"){
                if(si+1 >= park.size() || park[si+1][sj] == 0){
                    flag = true;
                    break;
                }
                si++;
            }
        }
        if(flag){
            si = fi;
            sj = fj;
        }
        cout << si << " " << sj << endl;
    }
    
    answer.push_back(si);
    answer.push_back(sj);
    return answer;
}
