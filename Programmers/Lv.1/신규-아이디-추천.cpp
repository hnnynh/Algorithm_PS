#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    vector<char> c;
    char prev = ' ';
    
    for(int i=0; i<new_id.length(); i++){       // 1, 2, 3
        if('A' <= new_id[i] && new_id[i] <= 'Z'){
            prev = new_id[i] - 'A' + 'a';
            c.push_back(prev);
        }
        else if(new_id[i] == '.'){
            if(prev == '.' || prev == ' ')
                continue;
            else{
                prev = '.';
                c.push_back(prev);
            }
        }
        else if(('a' <= new_id[i] && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_'){
            prev = new_id[i];
            c.push_back(prev);
        }
        else 
            continue;
    }
    
    int s = c.size();
    if(prev == '.')    // 4
        s--;
    
    if(s == 0){         // 5
        c.push_back('a');
        c.push_back('a');
        c.push_back('a');
        s = 3;
    }         
    else if(s >= 16){     // 6
        s = 15;
        if(c[14] == '.')
            s = 14;
    }
    else if(s <= 2){        // 7
        while(s < 3)
            c[s++] = c[s-1]; 
    }
    
    for(int i=0; i<s; i++)
        answer += c[i];
    
    return answer;
}