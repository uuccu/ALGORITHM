#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int rotate(vector<vector<int>> &matrix, vector<int> &query){
    int x1 = query[0] - 1;
    int y1 = query[1] - 1;
    int x2 = query[2] - 1;
    int y2 = query[3] - 1;
    
    int prev = matrix[x1][y1];
    int ans = 99999999;
    for(int i = y1; i <= y2; i++){
        int tmp = prev;
        prev = matrix[x1][i];
        matrix[x1][i] = tmp;
        ans = min(ans,prev);
        // cout<< prev << " ";
    }
    // cout<<endl;
    for(int i = x1 + 1; i <= x2; i++){
        int tmp = prev;
        prev = matrix[i][y2];
        matrix[i][y2] = tmp;
        ans = min(ans,prev);
        // cout<< prev << " ";
    }
    // cout<<endl;
    for(int i = y2 -1; i >= y1; i--){
        int tmp = prev;
        prev = matrix[x2][i];
        matrix[x2][i] = tmp;
        ans = min(ans,prev);
        // cout<< prev << " ";
    }
    // cout<<endl;
    for(int i = x2 - 1; i >= x1; i--){
        int tmp = prev;
        prev = matrix[i][y1];
        matrix[i][y1] = tmp;
        ans = min(ans,prev);
        // cout<< prev << " ";
    }
    // cout<<endl;
    // matrix[x1][y1] = prev;
    // ans = min(ans,prev);
    return ans;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> matrix(rows,vector<int>(columns,0));
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = j + i * columns + 1;
        }
    }
    
    for(auto query: queries){
        answer.push_back(rotate(matrix, query));
    }
    
    return answer;
}