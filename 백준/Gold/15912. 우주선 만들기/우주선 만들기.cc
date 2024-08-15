#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <list>
#include <cmath>

typedef long long ll;
#define endl "\n"
using namespace std;


ll dp[1001];
vector<ll> weight;
vector<ll> energy;


void solution() {
    ll n;
    cin >> n;
    weight = vector<ll>(n);
    energy = vector<ll>(n);

    for (auto &x: weight)cin >> x;
    for (auto &x: energy)cin >> x;

    fill(dp, dp + 1001, 1e14);
    dp[0] = weight[0] * energy[0];

    for (int i = 1; i < n; i++) {

        ll e_max = 0;
        ll w_max = 0;

        for (int j = i; j >= 1; --j) {
            w_max = max(w_max, weight[j]);
            e_max = max(e_max, energy[j]);

            dp[i] = min(dp[i], w_max * e_max + dp[j - 1]);
        }
        w_max = max(w_max, weight[0]);
        e_max = max(e_max, energy[0]);

        dp[i] = min(dp[i], w_max * e_max);
    }

    cout << dp[n - 1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    int testcase;
//    cin >> testcase;
//    while (testcase--)
    solution();
}
