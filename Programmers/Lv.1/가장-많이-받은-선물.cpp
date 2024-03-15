#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    vector<int> row(friends.size(), 0);
    vector<int> gs;
    vector<vector<int>> table(friends.size(), row);
    map<string, int> m;
    
    for(int i=0; i<friends.size(); i++){
        m[friends[i]] = i;
    }
    
    for(int i=0; i<gifts.size(); i++){
        string first, second;
        stringstream ss(gifts[i]);
        ss >> first >> second;
        table[m[first]][m[second]]++;
    }
    
    for(int i=0; i<friends.size(); i++){
        int sum = 0, sum1 = 0;
        for(int j=0; j<friends.size(); j++){
            sum += table[j][i];
            sum1 += table[i][j];
        }
        gs.push_back(sum1 - sum);
    } 

    for(int i=0; i<friends.size(); i++){
        for(int j=0; j<friends.size(); j++){
            if (i==j)
                continue;
            else if(table[i][j] == table[j][i]){    // 선물 지수 비교
                if(gs[i] > gs[j])
                    row[i]++;
                else if(gs[i] < gs[j])
                    row[j]++;
            }
            else if(table[i][j] > table[j][i]){
                row[i]++;
            }
            else if(table[i][j] < table[j][i]){
                row[j]++;
            }
        }
    }
    
    for(int i=0; i<friends.size(); i++){
        cout << row[i];
        if(answer < row[i])
            answer = row[i];
    }
   
    
    return answer / 2;
}
