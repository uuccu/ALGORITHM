#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> s, int k) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(auto x: s){
        pq.push(x);
    }
    
    while(pq.size() != 1){
        int x1 = pq.top();
        pq.pop();
        if(x1 >= k)return answer;
        int x2 = pq.top();
        pq.pop();
        
        int tmp = x1 + (x2 * 2);
        pq.push(tmp);
        answer++;
    }
    if(pq.top()>=k)return answer;
    answer = -1;
    
    return answer;
}