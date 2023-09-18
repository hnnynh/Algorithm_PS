#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int curL = 10, curR = 12;    

    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] == 0)
            numbers[i] = 11;
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            curL = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            curR = numbers[i];
        }
        else{
            int lx = (curL+2) % 3;
            int ly = (curL-1) / 3;
            int rx = (curR+2) % 3;
            int ry = (curR-1) / 3;
            int cx = (numbers[i]+2) % 3;
            int cy = (numbers[i]-1) / 3;
            int disL = abs(cx-lx) + abs(cy-ly);
            int disR = abs(cx-rx) + abs(cy-ry);
            
            if(disL > disR){
                answer += "R";
                if(numbers[i] == 0)
                    curR = 11;
                else
                    curR = numbers[i];
            }
            else if(disL < disR){
                answer += "L";
                if(numbers[i] == 0)
                    curL = 11;
                else
                    curL = numbers[i];
            }
            else if(disL == disR){
                if(hand == "left"){
                    answer += "L";
                    if(numbers[i] == 0)
                        curL = 11;
                    else
                        curL = numbers[i];
                }
                else{
                    answer += "R";
                    if(numbers[i] == 0)
                        curR = 11;
                    else
                        curR = numbers[i];
                }
            }       
        }
    }
    
    return answer;
}