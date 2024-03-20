#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;



int solution(vector<int> p, int l) {
    int answer = 0;
    priority_queue<pair<int,int>> pq;
    queue<pair<int,int>> q;
    
    int cnt = 0;
    for(auto x: p){
        q.push({x,cnt});
        pq.push({x,cnt++});
    }
    cnt = 1;
    while(!q.empty()){
        auto top = pq.top();
        auto cur = q.front();
        // cout<<top.first<<" "<<cur.first<<endl;
        
        if(top.first == cur.first){
            pq.pop();
            q.pop();
            if(cur.second == l)answer = cnt;
            cnt++;
        }else{
            q.pop();
            q.push(cur);
        }
    }
    
    return answer;
}