#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& key){
    int n = key.size();//정사각형
    vector<vector<int>> tempArr(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tempArr[i][j] = key[n-1-j][i];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            key[i][j] = tempArr[i][j];
        }
    }
    
}

bool moveCheck(vector<vector<int>>& key,vector<vector<int>>& lock, int upDown, int leftRight){
    // upDown는 상하 +는 상, -는 하
    // leftRight는 좌우 -는 우, +는 좌로 이동한다는 뜻
    int n = lock.size();
    vector<vector<int>> tempArr(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tempArr[i][j] = key[n-1-j][i];
        }
    }

    bool flag = true;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            int di = i + upDown;
            int dj = j + leftRight;
            if(di < 0 || di >= n || dj < 0 || dj >= n)tempArr[i][j] = 0;
            else tempArr[i][j] = key[di][dj];
            if(tempArr[i][j] == 1 && lock[i][j] != 0)flag = false;
            if(tempArr[i][j] == 0 && lock[i][j] == 0)flag = false;
        }
    }
    
    return flag;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // bfs로 풀려고 했지만, 생각해보니 순서는 중요하지 않다. 그래서 상하좌우로 모두 해보면 될듯. 
    bool answer = true; // 40 * 40 * 4 * 400 * check이니까 완탐을 해도 괜찮을 거 같다.
    
    // 열쇠 사이즈에 맞게 열쇠의 빈공간을 추가시킨다. 
    int n = lock.size();
    int m = key.size();
    vector<vector<int>> newKey(n,vector<int>(n,0));
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            newKey[i][j] = key[i][j];
        }
    }
    
    for(int r = 0; r < 4; r++){// 회전시키는 루프
        for(int i = 0; i < 41; i++){
            for(int j = 0; j<41; j++){
                // cout<<r <<" "<<i << " "<< j<<endl;
                if(moveCheck(newKey,lock,i- lock.size(),j -lock.size()))return true;
            }
        }
        rotate(newKey);
    }
    
    return false;
}