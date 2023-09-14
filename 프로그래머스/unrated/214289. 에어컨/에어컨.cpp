#include <string>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

int dp[1001][51]; // 현재 시간 ,현재온도,  지금까지의 최소 전력 사용량

const int MAX = 9999999;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    
    for(int i = 0; i<1001; i++){
        for(int j = 0; j<51; j++){
            dp[i][j] = MAX;
        }
    }
    temperature += 10;
    t1 += 10;
    t2 += 10;
    dp[0][temperature] = 0;

    int flag = temperature > t2 ? -1 : 1;
    // cout<<flag<<endl;
    // cout<< sizeof(dp)/sizeof(dp[0])<<endl;
    // cout<< sizeof(dp[0])/sizeof(int)<<endl;
    for(int i = 1; i < onboard.size(); i++){
        for(int j = 0; j < sizeof(dp[0])/sizeof(int); j++){
            int minValue = MAX;
            if((onboard[i] == 1 && j <= t2 && j >= t1) || onboard[i] == 0){
                // 에어컨 끄고 실외온도와 같은 경우
                if(temperature == j) 
                    minValue = min(minValue, dp[i-1][j]); 
                // 에어컨 끄고 실외온도와 다른 경우
                if(0 <= j + flag && j + flag <= 50)
                    minValue = min(minValue, dp[i-1][j + flag]);
                // 에어컨 키고 온도가 바뀌는 경우
                if(0 <= j - flag && j - flag <= 50)
                    minValue = min(minValue, dp[i-1][j - flag] + a);
                // 에어컨 키고 온도 유지
                if(t1 <= j && j <= t2) 
                    minValue = min(minValue, dp[i-1][j] + b); 
                dp[i][j] = minValue;
            }
        }
    }
    int answer = dp[onboard.size() - 1][0];
    // cout<< onboard.size(); 
    for(int i = 1; i < 51; i++){
        // cout<<dp[onboard.size()-1][i]<< endl;
        answer = min(answer, dp[onboard.size() - 1][i]);
    }
    return answer;
}