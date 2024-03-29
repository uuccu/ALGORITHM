#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int dp[101][10001] = {0,};// 해당 시점까지 최고 성적.

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int> > subjects;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        subjects.emplace_back(x, y);
    }// 입력 완

    for (int i = 0; i < n; i++) {
        int x = subjects[i].first, y = subjects[i].second;

        for (int j = 0; j <= t; j++) {
            if (j < x){
                dp[i+1][j] = dp[i][j];
            }else {
                dp[i+1][j] = max(dp[i][j], dp[i][j-x] + y);
            }
        }
    }

    cout<<dp[n][t];
}