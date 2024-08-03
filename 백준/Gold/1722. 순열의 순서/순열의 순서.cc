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

typedef long long ll;
#define endl "\n"
using namespace std;
//
//
//long long dp[1001][1001];
//
//long long weight_max[1001][1001];
//long long energy_max[1001][1001];
//
//vector<long long> weight;
//vector<long long> energy;
//
//long long recursive(long long l, long long r) {
//    if (dp[l][r] != -1)
//        return dp[l][r];
//
//    if (l == r) {
//        weight_max[l][r] = weight[l];
//        energy_max[l][r] = energy[l];
//        return dp[l][l] = weight[l] * energy[l];
//    }
//
//    long long min_ans = 2e12;
//    for (long long i = 1; i <= r - l; i++) {
//        min_ans = min(min_ans, recursive(l, l + i - 1) + recursive(l + i, r));
//        weight_max[l][r] = max(weight_max[l][r], max(weight_max[l][l + i - 1], weight_max[l + i][r]));
//        energy_max[l][r] = max(energy_max[l][r], max(energy_max[l][l + i - 1], energy_max[l + i][r]));
//    }
//    long long wm = *max_element(weight.begin() + l, weight.begin() + r + 1);
//    long long em = *max_element(energy.begin() + l, energy.begin() + r + 1);
//
//    weight_max[l][r] = max(weight_max[l][r], wm);
//    energy_max[l][r] = max(energy_max[l][r], em);
//
//    long long once_price = weight_max[l][r] * energy_max[l][r];
//
//    return dp[l][r] = min(min_ans, once_price);
//}
//
//void solution() {
//    long long n;
//    cin >> n;
//    weight = vector<long long>(n);
//    energy = vector<long long>(n);
//
//    for (auto &x: weight)cin >> x;
//    for (auto &x: energy)cin >> x;
//
//    memset(dp, -1, sizeof(dp));
//
//    cout << recursive(0, n - 1);
//}




void solution() {
    ll n, m;
    cin >> n >> m;


    auto factorial = [](ll num) -> ll {
        ll result = 1;
        for (int i = 2; i <= num; ++i) {
            result *= i;
        }
        return result;
    };


    if (m == 1) {
        ll idx;
        cin >> idx;
        list<int> li;
        vector<ll> ans;
        for (int i = 0; i < n; i++)li.push_back(i + 1);
        for (ll i = 0; i < n; i++) {
            ll fac = factorial(n - i - 1);

            for (auto it = li.begin(); it != li.end(); it++) {
                if (idx <= fac) {
                    ans.push_back(*it);
                    li.erase(it);
                    break;
                }
                idx -= fac;
            }
        }
        for (auto x: ans)cout << x << " ";
    } else {
        ll x;
        vector<int> v(n);
        ll ans = 1LL;
        for (int i = 0; i < n; i++) {
            v[i] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            ans += v[x - 1] * factorial(n - i - 1);
            for (ll j = x; j < n; j++)
                v[j]--;
        }
        cout << ans;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    int testcase;
//    cin >> testcase;
//    while (testcase--)
    solution();
}

