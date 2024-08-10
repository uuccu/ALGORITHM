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
    int r, c;
    cin >> r >> c;
    vector<string> v(r);

    for (auto &x: v)cin >> x;

    vector<pair<int, int>> vp;


    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] - '0' <= 9 && v[i][j] - '0' > 0) {
                vp.emplace_back(j, v[i][j] - '0');
                break;
            }
        }
    }

    sort(vp.begin(), vp.end(),greater<pair<int,int>>());

    int cnt = 0;
    int pos = -1;

    int rank[9];

    for (auto x: vp) {
        if (x.first != pos)rank[x.second - 1] = ++cnt;
        else rank[x.second - 1] = cnt;
        pos = x.first;
    }

    for (int i = 0; i < 9; i++)cout << rank[i] << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    int testcase;
//    cin >> testcase;
//    while (testcase--)
    solution();
}

