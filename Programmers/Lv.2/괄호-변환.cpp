#include <string>
#include <vector>

using namespace std;

bool check(string p){
    int l = 0;
    for(int i=0; i<p.size(); i++){
        if(p[i] == '(')
            l++;
        else if(p[i] == ')')
            l--;
        if(l < 0)
            return false;
    }
    return true;
}

string func(string p){
    
    if(p == "")
        return "";
    
    int l = 0, r = 0, idx;
    string u, v, answer = "";
    
    for(int i=0; i<p.size(); i++){
        if(p[i] == '(')
            l++;
        else if(p[i] == ')')
            r++;
        if(l == r){
            idx = i;
            break;
        }   
    }
    u = p.substr(0, ++idx);
    v = func(p.substr(idx));
    
    if(!check(u)){ 
        answer += "(";
        answer += v;
        answer += ")";
        for(int i=1; i<u.size()-1; i++){
            if(u[i] == '(')
                answer += ")";
            else if(u[i] == ')')
                answer += "(";
        }
        return answer;
    }

    return u + v;
}

string solution(string p) {
    if(check(p))
        return p;
    return func(p);
}
