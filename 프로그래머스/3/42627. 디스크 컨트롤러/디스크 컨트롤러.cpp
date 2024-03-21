#include <bits/stdc++.h>

using namespace std;


priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    for(auto x: jobs){
        pair<int,int> tmp;
        tmp.first = x[0];
        tmp.second = x[1];
        pq1.push(tmp);
    }
    int time = 0;
    
    while(!pq1.empty()){
        //pq1은 시작 시간을 기준으로
        //pq2은 소요되는 시간을 기준으로
        //pq1에서 pq2로 푸시하기.
        while(!pq1.empty()){
            auto x = pq1.top();
            if(time >= x.first){
                pq2.push({x.second,x.first});
                pq1.pop();
            }else{
                break;
            }
        }
        if(!pq2.empty()){
            auto x = pq2.top();
            pq2.pop();
            time += x.first;
            answer += (time - x.second);
        }else{ 
            time++;
        }
    }
    while(!pq2.empty()){
        auto x = pq2.top();
        pq2.pop();
        time += x.first;
        answer +=  (time - x.second);
    }
    
    answer = answer / jobs.size();
    return answer;
}