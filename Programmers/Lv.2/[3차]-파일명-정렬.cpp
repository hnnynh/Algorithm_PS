#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(vector<string> a, vector<string> b){
    if(a[1] == b[1]){
        if(stoi(a[2]) == stoi(b[2]))
            return stoi(a[0]) < stoi(b[0]);
        return stoi(a[2]) < stoi(b[2]);
    }
    return a[1] < b[1];
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> st;
    
    for(int i=0; i<files.size(); i++){
        int idx = 0;
        vector<string> temp;
        string str = "";
        temp.push_back(to_string(i));
        while(!('0' <= files[i][idx] && files[i][idx] <= '9'))
            idx++;
        
        for(int j=0; j<idx; j++){
            if('A' <= files[i][j] && files[i][j] <= 'Z')
                str += files[i][j] - 'A' + 'a';
            else 
                str += files[i][j];
        }
        temp.push_back(str);
        while(idx < files[i].size() && '0' <= files[i][idx] && files[i][idx] <= '9')
            idx++;
        temp.push_back(files[i].substr(temp[1].size(), idx));
        if (idx < files[i].size()){
            str = "";
            for(int j=idx; j<files[i].size(); j++){
                if('A' <= files[i][j] && files[i][j] <= 'Z')
                    str += files[i][j] - 'A' + 'a';
                else 
                    str += files[i][j];
            }
            temp.push_back(str);
        }
        st.push_back(temp);
    }
    
    sort(st.begin(), st.end(), cmp);
    
    for(int i=0; i<st.size(); i++){
        answer.push_back(files[stoi(st[i][0])]);
    }
    
    return answer;
}
