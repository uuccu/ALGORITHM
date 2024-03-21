#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> cs) {
    int answer = 0;
    sort(cs.begin(),cs.end());
    for(int i = 0; i <= 10000;i++){
        int tmp = upper_bound(cs.begin(),cs.end(),i) - cs.begin() - 1;
        // cout<<tmp<<endl;
        int cnt = cs.size() - tmp;
        if(cs[tmp] != i)cnt--;
        
        if(cnt >= i)answer = i;
    }
    // 0 1 3 5 6
    return answer;
}