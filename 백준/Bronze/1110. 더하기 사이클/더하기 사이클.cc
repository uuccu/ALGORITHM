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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v)cin >> x;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 2) {
        if (v[0] != v[1]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }

    int l = 0;
    int r = n - 1;

    int l_cur = v[0];
    int r_cur = v[n - 1];

    bool l_flag = false;
    bool r_flag = false;
    while (l <= r) {
        if (l == r) {
            if (v[0] == v[l]) {
                cout << 0 << endl;
                return;
            } else {
                cout << 1 << endl;
                return;
            }
        }
        if (l_flag && r_flag) {
            cout << r - l + 1 << endl;
            return;
        } else if (l_flag) {
            r--;
            if (r_cur != v[r]) {
                r_flag = true;
                cout << r - l + 1 << endl;
                return;
            }
        } else if (r_flag) {
            l++;
            if (l_cur != v[l]) {
                l_flag = true;
                cout << r - l + 1 << endl;
                return;
            }
        } else {
            if (l_cur == r_cur) {
                l++;
                r--;
                if (l_cur != v[l]) {
                    l_flag = true;
                }
                if (r_cur != v[r]) {
                    r_flag = true;
                }
            } else {
                if (l_cur == v[l + 1]) {
                    l++;
                    r_flag = true;
                } else if (r_cur == v[r - 1]) {
                    r--;
                    l_flag = true;
                } else {// 둘다 다름.
                    cout << r - l << endl;
                    return;
                }
            }
        }
        l_cur = v[l];
        r_cur = v[r];
    }

    if (l > r) {
        cout << 0 << endl;
    } else {
        cout << r - l + 1 << endl;
    }

}


int main() {

    int n;
    cin >> n;

    if(n < 10)n *=10;
    int prev = n;

//    n *= 10;

    int cnt = 0;
    while (true) {
        int cur = (prev % 10) * 10 + (prev / 10 + prev % 10) % 10;

        cnt++;
        if (cur == n)break;
//        if (cur < 10)cur *= 10;
        prev = cur;
    }

    cout << cnt;
}
