#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;



int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0}; 

bool visited[5][5] = {false,};

bool isRange(int x, int y){
    if(x < 0 || x >= 5 || y < 0 || y >= 5)return false;
    if(visited[x][y])return false;
    return true;
}

bool bfs(int x, int y, int distance, vector<string> & place){
    if(distance == 2)return false;
    // visited[x][y] = true;

    for(int i = 0; i <4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        
        if(!isRange(tx,ty))continue;
        visited[tx][ty] = true;
        
        if(place[tx][ty] == 'P')return true;
        if(place[tx][ty] == 'X')continue;
        
        if(bfs(tx,ty,distance+1,place) == true)return true;
    }
    
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place: places){
        int ans = 1;
        for(int i = 0; i< 5; i++){
            for(int j = 0; j < 5; j++){
                if(place[i][j] == 'P'){
                    memset(visited,false,sizeof(bool)*5*5);
                    visited[i][j] = true; 
                    if(bfs(i,j,0,place) == true) ans= 0;
                }
            }
        }
        answer.push_back(ans);
    }
    return answer;
}