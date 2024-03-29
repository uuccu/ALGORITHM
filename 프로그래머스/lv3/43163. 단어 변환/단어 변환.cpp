#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int countDifference(string cur, string next){
    int cnt = 0;
    for(int i =0; i< cur.length(); i++){
        if(cur[i] != next[i])cnt++;
    }
    return cnt;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string,int>> q;
    q.push({begin,0});
    vector<bool> visited(words.size(),false);
    
    while(!q.empty()){
        const auto [cur, cnt] = q.front();
        q.pop();
        
        if(countDifference(cur,target) == 0 )return cnt;
        
        for(int i = 0; i < words.size(); i++){
            if(countDifference(cur, words[i]) == 1 && !visited[i]){
                q.push({words[i],cnt + 1});
                visited[i] = true;
            }
        }
    }
    
    return 0;
}