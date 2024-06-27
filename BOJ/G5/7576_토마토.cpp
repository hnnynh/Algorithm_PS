#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int M, N, temp, cnt = 0, no = 0, answer = 0;
    vector<vector<int>> box;
    queue<pair<int, int>> q;
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < M; j++) {
            cin >> temp;
            v.push_back(temp);
            if(temp == 1)
                q.push({ i, j });
        }
        box.push_back(v);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (box[nx][ny] == 0) {
                    box[nx][ny] = box[x][y] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (answer < box[i][j])
                answer = box[i][j];
        }
    }
    
    cout << answer - 1;
}
