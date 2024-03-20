#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0;i<p.size();i++){
        int left = 100 - p[i];
        int speed = s[i];
        int left_day = left/speed;
        if(left % speed!=0)left_day++;
        q.push(left_day);
    }
    int prev = 0;
    while(!q.empty()){
        int cnt = 1;
        prev = q.front();
        q.pop();
        
        while(!q.empty()){
            if(prev >= q.front()){
                q.pop();
                cnt++;
            }else{
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}