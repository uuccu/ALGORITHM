#include <bits/stdc++.h>

using namespace std;

int answer = 1;
int visited[1<<17];

int l[20];// 해당 노드번호의 왼쪽 자식의 번호가 들어있음.
int r[20];
int n;


void dfs(int state, vector<int>& info){
    if(visited[state])return;//방문했었다면 return
    visited[state] = 1;
    int wolf = 0, sheep = 0;
    
    for(int i = 0; i<n;i++){
        if(state & 1<<i){
            sheep++;
            wolf += info[i];
        }
    }
    sheep -= wolf;
    if(sheep <= wolf)return;
    
    answer = max(answer,sheep);
    for(int i = 0; i<n;i++){
        if(!(state & (1<<i)))continue;// i번째가 0인 경우
        if(l[i] != -1)dfs(state | (1<<l[i]),info);// 왼쪽에 자식이있는경우 왼쪽 자식노드로 이동
        if(r[i] != -1)dfs(state | (1<<r[i]),info);
    }
    
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    fill(l,l+n,-1);
    fill(r,r+n,-1);
    
    for(int i = 0; i< n-1; i++){
        int parent = edges[i][0];
        int child = edges[i][1];
        
        if(l[parent] == -1)l[parent] = child;
        else r[parent] = child;
    }
    
    dfs(1,info);
    return answer;
}