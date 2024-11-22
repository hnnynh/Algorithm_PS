#include <iostream>
#include <map>

using namespace std;

int board[5][5];

int check(){
    int count = 0;
    for(int i=0; i<5; i++){
        int rs = 0, cs = 0;
        for(int j=0; j<5; j++){
            rs += board[i][j];
            cs += board[j][i];
        }
        if(cs == 0)
            count++;
        if(rs == 0)
            count++;
    }
    
    int cal1 = 0, cal2 = 0;
    for(int i=0; i<5; i++){
        cal1 += board[i][i];
        cal2 += board[4-i][i];
    }
    if(cal1 == 0)
        count++;
    if(cal2 == 0)
        count++;
    
    return count;
}

int main()
{
    int num;
    map<int, pair<int, int>> m;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> board[i][j];
            m[board[i][j]] = {i,j};
        }
    }
    
    for(int i=0; i<11; i++){
        cin >> num;
        board[m[num].first][m[num].second] = 0;
    }
    
    for(int i=0; i<14; i++){
        cin >> num;
        board[m[num].first][m[num].second] = 0;
        if(check() >= 3){
            cout << 12+i << endl << endl;
            break;
        }
    }
    

    return 0;
}
