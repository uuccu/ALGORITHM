#include <bits/stdc++.h>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    // k * sqrt(a^2 + b^2) <= d
    
    for(int i = 0; i*k <= d; i++){
        answer += floor(sqrt(pow(d,2) - pow(i*k,2))/ k) + 1;
    }
    
    
    
    return answer;
}