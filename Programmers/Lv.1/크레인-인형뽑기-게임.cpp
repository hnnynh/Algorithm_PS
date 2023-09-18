#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    
    for(int i=0; i<moves.size(); i++){
        int temp = -1;
        for(int j=0; j<board.size(); j++){
            if(board[j][moves[i]-1] != 0){
                temp = board[j][moves[i]-1];
                board[j][moves[i]-1] = 0;
                break;
            }
        }
        if(temp < 0)
            continue;
        
        if(!st.empty()){
            if(st.top() == temp){
                st.pop();
                answer += 2;
            }
            else
                st.push(temp);
        }
        else
           st.push(temp);
    }
    
    return answer;
}