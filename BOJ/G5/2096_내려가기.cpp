#include<iostream>
#include<vector>

using namespace std;

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int N, temp0, temp2;
    vector<int> maxdp(3, 0), mindp(3, 0), input(3, 0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input[0] >> input[1] >> input[2];
        
        temp0 = maxdp[0];
        temp2 = maxdp[2];
        maxdp[0] = input[0] + max(maxdp[0], maxdp[1]);
        maxdp[2] = input[2] + max(maxdp[1], maxdp[2]);
        maxdp[1] = input[1] + max(maxdp[1], max(temp0, temp2));

        temp0 = mindp[0];
        temp2 = mindp[2];
        mindp[0] = input[0] + min(mindp[0], mindp[1]);
        mindp[2] = input[2] + min(mindp[1], mindp[2]);
        mindp[1] = input[1] + min(mindp[1], min(temp0, temp2));
    }

    cout << max(maxdp[0], max(maxdp[1], maxdp[2])) << " " << min(mindp[0], min(mindp[1], mindp[2]));
}
