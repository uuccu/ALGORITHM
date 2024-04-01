#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto c: commands){
        int i = c[0];
        int j = c[1];
        int k = c[2];
        vector<int> tmp;
        for(i = c[0]-1; i < j; i++){
            tmp.push_back(array[i]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[k-1]);
    }
    
    return answer;
}