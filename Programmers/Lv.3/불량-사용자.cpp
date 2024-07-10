#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> id_list;

bool check(string a, string b) {
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i] && b[i] != '*') 
                return false;
        }
    }
    else 
        return false;
    return true;
}


int solution(vector<string> user_id, vector<string> banned_id) {
    sort(user_id.begin(), user_id.end());
    
    do{
        string id = "";
        vector<string> temp;
        for(int i=0; i<banned_id.size(); i++){
            if(check(user_id[i], banned_id[i]))
                temp.push_back(user_id[i]);
        }
        
        if(temp.size() == banned_id.size()){
            sort(temp.begin(), temp.end());
            for(int i=0; i<temp.size(); i++){
                id += temp[i];
            }
            id_list.insert(id);
        }
        
    } while(next_permutation(user_id.begin(), user_id.end()));
    
    return id_list.size();
}
