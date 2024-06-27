#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int i=0; i<places.size(); i++){
        vector<pair<int, int>> people;
        vector<pair<int, int>> check;
        bool ch = true;

        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(places[i][j][k] == 'P')
                    people.push_back({j, k});
                
            }
        }
        
        for(int j=0; j<people.size(); j++){
            for(int k=j+1; k<people.size(); k++){
                int r = abs(people[j].first - people[k].first);
                int c = abs(people[j].second - people[k].second);
                if(r+c == 2)    
                    check.push_back({j, k});
                else if(r+c <= 1)
                    ch = false;
            }
        }
        
        if(!ch){
            answer.push_back(0);
            continue;
        }
        if(check.size() == 0){
            answer.push_back(1);
            continue;
        }
        
        for(int j=0; j<check.size(); j++){
            int idx1 = check[j].first;
            int idx2 = check[j].second;
            
            if(people[idx1].first == people[idx2].first){
                if(places[i][people[idx1].first][(people[idx1].second + people[idx2].second)/2] == 'O'){
                    ch = false;
                    break;
                }     
            }
            else if(people[idx1].second == people[idx2].second){
                if(places[i][(people[idx1].first + people[idx2].first)/2][people[idx1].second] == 'O'){
                    ch = false;
                    break;
                }
            }
            else{
                if(places[i][people[idx1].first][people[idx2].second] == 'O' || places[i][people[idx2].first][people[idx1].second] == 'O'){
                    ch = false;
                    break;
                }
            }
        }
        
        if(!ch)
            answer.push_back(0);
        else
            answer.push_back(1);
    }
    
    return answer;
}
