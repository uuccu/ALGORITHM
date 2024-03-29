#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();


    priority_queue<int, vector<int>, greater<>> pq;
    pq.push(numbers[n - 1]);
    for (int i = n - 1; i >= 0; i--) {
        int cur = numbers[i];
        bool flag = false;
        if (i == n - 1) {
            answer.push_back(-1);
            continue;
        }
        while (!pq.empty()) {
            int x = pq.top();
            if (cur >= x) {
                pq.pop();
            } else {
                answer.push_back(x);
                pq.push(cur);
                flag = true;
                break;
            }
        }
        if (!flag) {
            answer.push_back(-1);
            pq.push(cur);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}