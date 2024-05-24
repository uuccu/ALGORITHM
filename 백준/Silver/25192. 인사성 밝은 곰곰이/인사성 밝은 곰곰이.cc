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


void solution() {
    int n;
    cin >> n;
    string s;

    int cnt = 0;

    set<string> se;

    while (n--) {
        cin >> s;

        if (s == "ENTER") {
            se.clear();
        } else if (se.find(s) == se.end()) {
            cnt++;
            se.insert(s);
        }
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    int testcase;
//    cin >> testcase;
//    while (testcase--)
    solution();

}

