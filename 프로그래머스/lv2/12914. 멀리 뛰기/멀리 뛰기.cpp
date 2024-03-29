#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int n) {
    vector<int> dp(2001, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i = 4; i < 2001; i++){
        dp[i] = (dp[i-1] + dp[i -2]) %1234567;
    }
    
    return dp[n];
}