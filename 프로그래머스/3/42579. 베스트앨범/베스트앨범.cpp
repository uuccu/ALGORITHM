#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool comp(pair<string,int> x1, pair<string,int> x2){
    return x1.second > x2.second;
}

bool comp2(pair<int,int> x1, pair<int,int> x2){
    return x1.first > x2.first;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> m;
    unordered_map<string,vector<pair<int,int>>> mm;
    
    for(int i = 0; i < plays.size();i++){
        m[genres[i]] += plays[i];
        mm[genres[i]].push_back({plays[i],i});
    }
    
    vector<pair<string,int>> v(m.begin(),m.end());
    
    sort(v.begin(),v.end(),comp);
    
    for(auto &x: mm){
        sort(x.second.begin(),x.second.end(),comp2);
        // for(auto y: x.second){
        //     cout<< y.first << " "<<y.second<<endl;
        // }
    }
    
    for(auto x: v){
        string genre = x.first;
        
        int sz =  mm[genre].size();
        
        answer.push_back(mm[genre][0].second);
        if(sz > 1)answer.push_back(mm[genre][1].second);
    }
    
    return answer;
}