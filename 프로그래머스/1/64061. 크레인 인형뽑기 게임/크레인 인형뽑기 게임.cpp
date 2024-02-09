#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    
    stack<int> s;
    
    for(auto x: moves){
        int cur = x - 1;
        for(int i = 0; i< n; i++){
            if(board[i][cur] != 0) {
                if(s.empty()){
                    s.push(board[i][cur]);
                }
                else if(board[i][cur] == s.top()){
                    s.pop();
                    answer += 2;
                }else{
                    s.push(board[i][cur]);
                }
                board[i][cur] = 0;
                break;
            }
        }
    }
    
    return answer;
}