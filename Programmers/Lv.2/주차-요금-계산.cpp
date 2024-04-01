#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> car, ans;
    map<int, string> enter;     // 차량번호, 입차 시각
    map<int, int> time;         // 차량번호, 누적 시간

    for(auto r:records){
        string t, io;
        int c;
        stringstream ss(r);
        ss >> t >> c >> io;
        
        if(io == "IN"){
            car.push_back(c);
            enter[c] = t;
            if(time[c] < 0)
                time[c] = 0;
        } else if(io == "OUT"){
            int cal = 0;
            string e = enter[c];
            enter[c] = "";
            cal += (t[0] - e[0]) * 10 * 60;
            cal += (t[1] - e[1]) * 60;
            cal += (t[3] - e[3]) * 10;
            cal += (t[4] - e[4]);
            time[c] += cal;
        }  
    }
    sort(car.begin(), car.end());
    
    for(auto l:car){
        if(enter[l] != ""){
            string e = enter[l];
            int cal = 0;
            enter[l] = "";
            cal += ('2' - e[0]) * 10 * 60;
            cal += ('3' - e[1]) * 60;
            cal += ('5' - e[3]) * 10;
            cal += ('9' - e[4]);
            time[l] += cal;
        }
    }

    for(auto l:car){
        if(time[l] <= 0){
            continue;
        }
        else if(0 < time[l] && time[l] <= fees[0]){
            ans.push_back(fees[1]);
        }
        else if(fees[0] < time[l]){
            time[l] -= fees[0];
            if(time[l] % fees[2] == 0)
                ans.push_back((time[l]/fees[2])*fees[3] + fees[1]);
            else
                ans.push_back((time[l]/fees[2]+1)*fees[3] + fees[1]);;
        }
        time[l] = 0;
    }
    
    return ans;
}
