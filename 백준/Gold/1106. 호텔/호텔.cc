#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <stack>


#define endl "\n"
using namespace std;
int n, c;

int dp[1101];

int recur(int customer, int cityNum, vector<pair<int, int>> &v) {

    int _min = 100 * 1000;
    int cost = 0;

    if (customer <= 0)return 0;

    else if (dp[customer] > 0)return dp[customer];

    else {
        for (int i = 0; i < cityNum; i++) {
            cost = recur(customer - v[i].second, cityNum, v) + v[i].first;
            _min = min(_min, cost);
        }
        dp[customer] = _min;
    }

    return _min;
}

void solution() {
    cin >> c >> n;

    vector<pair<int, int>> v(n);
    for (auto &x: v)cin >> x.first >> x.second;

    sort(v.begin(), v.end());

    cout << recur(c, n, v);


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    int testcase;
//    cin >> testcase;
//    while (testcase--)
    solution();

}

