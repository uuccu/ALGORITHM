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
int n;
vector<int> init_state;
vector<int> effect[21];


void solution() {
    int n;
    cin >> n;

    while (n != 1) {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                n /= i;
                cout << i << endl;
                break;
            }
        }
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

