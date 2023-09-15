#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxValue = 0;
        int prev = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] <= prev){
                prev = prices[i];
                continue;
            }
            maxValue = max(prices[i] - prev, maxValue);
        }
        
        return maxValue;
    }
};