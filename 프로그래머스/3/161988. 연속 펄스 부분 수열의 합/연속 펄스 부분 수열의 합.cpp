#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;

    long long purse1 = 0;
    long long purse2 = 0;

    bool d = true;

    for(auto x : sequence){
        purse1 += d ? x: -x;
        purse2 += d ? -x: x;

        purse1 = max(0LL,purse1);
        purse2 = max(0LL,purse2);

        answer = max(answer,max(purse1,purse2));
        d = !d;
    }
    return answer;
}