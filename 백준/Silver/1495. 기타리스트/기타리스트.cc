#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;
int n, s, m;
vector<int> v;

int dp[51][1001] = {-1,};//

int recursive(int step, int cur_volume) {
    if (cur_volume > m || cur_volume < 0)return -2;//???
    if (step == n)return dp[step][cur_volume] = cur_volume;// base case
    if (dp[step][cur_volume] != -1) {
        return dp[step][cur_volume];
    }

    dp[step][cur_volume] = 0;

    return dp[step][cur_volume] = max(recursive(step + 1,cur_volume + v[step]), recursive(step + 1,cur_volume - v[step]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> m;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    dp[0][s] = recursive(0, s);
    if(dp[0][s] == -2)cout<<-1;
    else
        cout << dp[0][s];
}