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


vector<string> answer;
bool visited[100000001];
bool check = false;

void dfs(string cur, vector<vector<string>> &tickets, int cnt) {
    if (cnt == tickets.size()) {
        check = true;
    }
    answer.push_back(cur);
    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == cur){
            visited[i] = true;
            dfs(tickets[i][1],tickets,cnt+1);
            if(!check){
                visited[i] = false;
                answer.pop_back();
            }
        }
    }


}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());

    dfs("ICN", tickets, 0);

    return answer;
}