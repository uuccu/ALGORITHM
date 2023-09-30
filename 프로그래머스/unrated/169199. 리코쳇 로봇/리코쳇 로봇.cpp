#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;
bool isColision(int x, int y,vector<string>& board){
    if(x < 0 || x >= n || y >= m || y <0)return true;
    if(board[x][y] == 'D') return true;
    return false;
}

int solution(vector<string> board) {
    int answer = 0;
    n = board.size();
    m = board[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));// 멈춘 지점 방문했는지 표시.
    
    queue<pair<int,pair<int,int>>> q;
    pair<int,int> robot; 
    for(int i = 0; i<n; i++){
        for(int j = 0; j< m;j++){
            if(board[i][j] == 'R')robot = {i,j};
        }
    }
    
    q.push({0,robot});
    visited[robot.first][robot.second];
    
    while(!q.empty()){
        const auto [cost, pos] = q.front();
        const auto [x,y] = pos;
        
        q.pop();
        if(board[x][y] =='G')return cost;
        
        for(int i = 0; i< 4; i++){
            int nx = x;
            int ny = y;
            while(true){
                nx += dx[i];
                ny += dy[i];
                if(isColision(nx,ny,board)){// 충돌한 경우 
                    nx -= dx[i];
                    ny -= dy[i];
                    if(!visited[nx][ny]){ // 방문 안했으면 추가
                        q.push({cost+1,{nx,ny}});
                        visited[nx][ny] = true;
                    }
                    break; 
                }
                // 충돌 안한경우 한번더 이동
            }   
        }
    }
    return -1;
}