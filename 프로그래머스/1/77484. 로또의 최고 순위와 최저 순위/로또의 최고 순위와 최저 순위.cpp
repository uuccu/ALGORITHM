#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> s;
    
    for(auto x: win_nums){
        s.insert(x);
    }
    int min = 0;
    int max = 0;
    
    for(auto x: lottos){
        if(x == 0){
            max++;
        }else if(s.find(x) != s.end()){
            max++;
            min++;
        }
    }
    
    if(max == 0)max = 1;
    if(min == 0)min = 1;
    
    answer.push_back(7-max);
    answer.push_back(7-min);
    
    return answer;
}