#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> v1, vector<int> v2) {
    int answer = 0;
    // greed로 구현, 300000번 이상 넘어가면 -1을 리턴

    long long s1 = 0LL, s2 = 0LL;
    
    queue<int> q1;
    queue<int> q2;
    for(int i = 0; i < v1.size(); i++){
        s1 += v1[i];
        s2 += v2[i];
        q1.push(v1[i]);
        q2.push(v2[i]);
    }
    
    while(answer < 300000){
        if(s1 == s2){
            return answer;
        }else if(s1 > s2){
            int x = q1.front();
            q1.pop();
            q2.push(x);
            s1 -= x;
            s2 += x;
        }else{
            int x = q2.front();
            q2.pop();
            q1.push(x);
            s1 += x;
            s2 -= x;
        }
        answer++;
    }
    return -1;
}