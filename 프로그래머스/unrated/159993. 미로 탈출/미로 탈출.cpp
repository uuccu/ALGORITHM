#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int solution(vector<string> maps) {
    int answer = 0;
    pair<int,int> start;
    
    int N = maps.size();
    int M = maps[0].length();
    
    for(int i= 0; i< N;i++){
        for(int j = 0; j<M;j++){
            if(maps[i][j] == 'S') start ={i,j};
        }
    }
    
    queue<pair<int,pair<int,int>>> pq;
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    pq.push({0,start});
    visited[start.first][start.second] = true;
    
    bool isBreak = true;
    
    while(!pq.empty()){//from start to lever
        const auto  [cost, pos] = pq.front();
        const auto [x, y] = pos;
        pq.pop();
        if(maps[x][y] == 'L'){
            isBreak = false;
            answer += cost;
            start = {x,y};
            break;
        }
        
        for(int i =0; i< 4; i++){
            auto _x = x + dx[i];
            auto _y = y + dy[i];
            if(_x >= N || _x < 0 || _y >= M || _y <0)continue;
            if( !visited[_x][_y] && maps[_x][_y] != 'X'){
                pq.push({cost + 1,{_x,_y}});
                visited[_x][_y] = true;
            }
        }
    }
    if(isBreak)return -1;
    
    //리셋
    pq = queue<pair<int,pair<int,int>>>();
    visited= vector<vector<bool>>(N,vector<bool>(M,false));
    pq.push({0,start});
    visited[start.first][start.second] = true;
    isBreak = true;
    
    while(!pq.empty()){// from lever to end
        const auto [cost, pos] = pq.front();
        const auto [x, y] = pos;
        pq.pop();
        if(maps[x][y] == 'E'){
            isBreak = false;
            answer += cost;
            break;
        }
        
        for(int i =0; i< 4; i++){
            auto _x = x + dx[i];
            auto _y = y + dy[i];
            if(_x >= N || _x < 0 || _y >=M || _y < 0)continue;
            if( !visited[_x][_y] && maps[_x][_y] != 'X'){
                pq.push({cost + 1,{_x,_y}});
                visited[_x][_y] = true;
            }
        }
    }
    if(isBreak)return -1;

    return answer;
}

