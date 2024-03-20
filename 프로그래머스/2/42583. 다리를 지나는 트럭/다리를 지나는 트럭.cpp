#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int b, int w, vector<int> t) {
    int answer = 0;
    
    queue<pair<int,int>> q;
    int second = 0;
    int w_sum = 0;
    q.push({t[0],second++});
    w_sum+=t[0];
    t.erase(t.begin());
    
    while(!q.empty()){
        auto cur = q.front();
        if(second - cur.second >= b){
            q.pop();
            w_sum -= cur.first;
        }
        if(!t.empty() && w_sum + t[0] <= w){
            q.push({t[0],second});
            w_sum+=t[0];
            t.erase(t.begin());
        }
        second++;
    }
    
    return second;
}