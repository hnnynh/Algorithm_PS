#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string s1[4] = {"-", "cpp", "java", "python"};
    string s2[3] = {"-", "backend", "frontend"};
    string s3[3] = {"-", "junior", "senior"};
    string s4[3] = {"-", "chicken", "pizza"};
    unordered_map<string, vector<int>> scores;
    
    for(auto i:info){
        string lang, part, car, food;
        int score;
        stringstream ss(i);
        ss >> lang >> part >> car >> food >> score;
        
        scores[lang+part+car+food].push_back(score);
        scores["-"+part+car+food].push_back(score);
        scores[lang+"-"+car+food].push_back(score);
        scores[lang+part+"-"+food].push_back(score);
        scores[lang+part+car+"-"].push_back(score);
        scores["--"+car+food].push_back(score);
        scores["-"+part+"-"+food].push_back(score);
        scores["-"+part+car+"-"].push_back(score);
        scores[lang+"--"+food].push_back(score);
        scores[lang+"-"+car+"-"].push_back(score);
        scores[lang+part+"--"].push_back(score);
        scores["---"+food].push_back(score);
        scores["--"+car+"-"].push_back(score);
        scores["-"+part+"--"].push_back(score);
        scores[lang+"---"].push_back(score);
        scores["----"].push_back(score);
    }
    
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    sort(scores[s1[i]+s2[j]+s3[k]+s4[l]].begin(), scores[s1[i]+s2[j]+s3[k]+s4[l]].end());
                }
            }
        }
    }
    
    for(auto q:query){
        string lang, part, car, food, a;
        int score, mid = 0, cnt = 0;
        stringstream ss(q);
        ss >> lang >> a >> part >> a >> car >> a >> food >> score;
      
        auto it = lower_bound(scores[lang+part+car+food].begin(), scores[lang+part+car+food].end(), score);
        answer.push_back(scores[lang+part+car+food].size() - (it - scores[lang+part+car+food].begin()));
    }
    
    return answer;
}
