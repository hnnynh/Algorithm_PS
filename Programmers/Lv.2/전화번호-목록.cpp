#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(string a, string b){
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    map<string, bool> m;
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    for(int i=0; i<phone_book.size(); i++){
        m[phone_book[i]] = true;
    }
    
    for(int i=0; i<phone_book.size(); i++){
        string str = phone_book[i];
        string temp = "";
        for(int j=0; j<str.size()-1; j++){
            temp += str[j];
            if(m[temp])
                return false;
        }
    }
    
    return true;
}
