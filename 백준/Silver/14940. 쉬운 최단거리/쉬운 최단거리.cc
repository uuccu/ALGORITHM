#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;


int n, m;
int board[1001][1001];
bool visited[1001][1001];
pair<int, int> start;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int aa;
            cin>>aa;
            board[i][j] = -aa;
            if (aa == 2) {
                start.first = i;
                start.second = j;
            }
        }
    }

    queue<pair<int,pair<int, int>>> q;

    q.emplace(0,start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto fr = q.front();
        auto cnt = fr.first;
        auto cur = fr.second;
        board[cur.first][cur.second] = cnt;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if(x < 0  || x > n || y < 0 || y >m)continue;
            if(visited[x][y])continue;
            if(board[x][y] == 0)continue;
            q.push({cnt+1,{x,y,}});
            visited[x][y] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j]<< " ";
        }
        cout<<endl;
    }

}