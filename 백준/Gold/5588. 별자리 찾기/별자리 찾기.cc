#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <stack>


using namespace std;


int main() {
    int n, m;
    cin >> m;//200

    set<pair<int, int>> s;
    vector<pair<int, int>> stars(m);
    for (auto &x: stars) {
        cin >> x.first >> x.second;
    }

    cin >> n;//1000
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
    }

    int dx = 0, dy = 0;
    int ansX, ansY;
    for (auto it = s.begin(); it != s.end(); it++) {//n picture
        for (int i = 0; i < m; i++) {//stars
            if (i == 0) {
                dx = it->first - stars[i].first;
                dy = it->second - stars[i].second;
            } else {
                if (s.find({dx + stars[i].first, dy + stars[i].second}) == s.end()) {
                    break;
                }
                if(i == m-1){
                    ansX = dx;
                    ansY = dy;
                }
            }
        }
    }
    cout << ansX << " " << ansY << endl;
}