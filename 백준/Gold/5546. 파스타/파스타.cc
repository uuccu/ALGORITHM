#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <stack>


using namespace std;

long long dp[100][3][2];

int main() {
    long long answer = 0;
    int n, k;
    cin >> n >> k;// 2일 연속만 허용.

    vector<int> v(n);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        v[x - 1] = y;
    }

    if (v[0] != 0) {
        dp[0][v[0] - 1][0] = 1;
    } else {
        dp[0][0][0] = 1;
        dp[0][1][0] = 1;
        dp[0][2][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (v[i] == 0) {
            dp[i][0][0] = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][2][0] + dp[i - 1][2][1])%10000;
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][2][0] + dp[i - 1][2][1])%10000;
            dp[i][1][1] = dp[i - 1][1][0];
            dp[i][2][0] = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][0][0] + dp[i - 1][0][1])%10000;
            dp[i][2][1] = dp[i - 1][2][0];
        } else if (v[i] == 1) {
            dp[i][0][0] = dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][2][0] + dp[i - 1][2][1];
            dp[i][0][1] = dp[i - 1][0][0];
        } else if (v[i] == 2) {
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][2][0] + dp[i - 1][2][1])%10000;
            dp[i][1][1] = dp[i - 1][1][0];
        } else if (v[i] == 3) {
            dp[i][2][0] = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][0][0] + dp[i - 1][0][1])%10000;
            dp[i][2][1] = dp[i - 1][2][0];
        }
    }


    answer += dp[n - 1][0][0];
    answer += dp[n - 1][1][0];
    answer += dp[n - 1][2][0];
    answer += dp[n - 1][0][1];
    answer += dp[n - 1][1][1];
    answer += dp[n - 1][2][1];
    
    answer %= 10000;

    cout << answer;

}