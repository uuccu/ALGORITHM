#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> ps) {
    vector<int> answer(ps.size(), 0);
    stack<pair<int, int>> s;
    int i;
    for (i = 0; i < ps.size(); i++) {
        do {
            if (s.empty()) {
                s.emplace(ps[i], i);
                break;
            }
            auto cur = s.top();
            if (ps[i] < cur.first) {
                s.pop();
                answer[cur.second] = i - cur.second;
                if(s.empty()) s.emplace(ps[i],i);
            } else {
                s.emplace(ps[i], i);
                break;
            }
        } while (!s.empty());
    }
    i--;
    while(!s.empty()){
        auto cur = s.top();
        s.pop();
        answer[cur.second] = i - cur.second;
    }

    return answer;
}