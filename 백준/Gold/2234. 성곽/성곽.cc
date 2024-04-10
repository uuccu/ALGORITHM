#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <stack>


#define endl "\n"
using namespace std;
int n, m;
vector<vector<int>> arr;
vector<vector<bool>> visited;

int di[] = {1, 2, 4, 8};
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool isRange(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)return false;
    if (visited[x][y]) return false;
    return true;
}

bool isWall(int x, int y, int flag) {
    return arr[x][y] & flag;
}

int dfs(int x, int y) {
    visited[x][y] = true;
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int cx = dx[i] + x;
        int cy = dy[i] + y;
        if (isRange(cx, cy) && !isWall(x, y, di[i])) {
            cnt += dfs(cx, cy);
        }
    }

    return cnt;
}

void solution() {
    cin >> m >> n;
    arr = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    int cnt = 0;
    int max_cnt = 0;
    for (auto &x: arr)
        for (auto &y: x)cin >> y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                cnt++;
                max_cnt = max(max_cnt, dfs(i, j));
            }
        }
    }

    cout << cnt << endl << max_cnt << endl;
    visited = vector<vector<bool>>(n, vector<bool>(m, false));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k: di) {
                if (isWall(i, j, k)) {
                    visited = vector<vector<bool>>(n, vector<bool>(m, false));
                    arr[i][j] -= k;
                    max_cnt = max(max_cnt, dfs(i, j));
                    arr[i][j] += k;
                }
            }
        }
    }

    cout << max_cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    int testcase;
//    cin >> testcase;
//    while (testcase--)
    solution();

}

