#include<iostream>
#include<queue>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    int N, max = 1, days = 0;
    int cheese[101][101];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cheese[i][j];
            days = cheese[i][j] > days ? cheese[i][j] : days;
        }
    }

    for (int d = 0; d <= days; d++) {
        int cnt = 0;
        bool visited[101][101] = { false, };
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && cheese[i][j] > d) {
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    visited[i][j] = true;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (0 <= nx && nx < N && 0 <= ny && ny<N && !visited[nx][ny] && cheese[nx][ny]>d) {
                                q.push({ nx, ny });
                                visited[nx][ny] = true;
                            }
                        }

                    }
                }
            }
        }
        max = max < cnt ? cnt : max;
    }
    cout << max;

    return 0;
}
