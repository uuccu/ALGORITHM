#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<double,int> f, pair<double,int> s){
    if(f.first >= s.first){
        if(f.first == s.first)return f.second < s.second;
        return true;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    // 실패율이 높은 애부터, 같으면 작은번호가 우선되게
    // N+1은 모든걸 다깸.
    vector<int> ch(N,0);
    vector<int> sum(N,0);

    
    for(int i = 0; i < stages.size(); i++){
        int stage = stages[i];
        if(stage != N+1) ch[stage-1]++;
        for(int j = 0; j < stage;j++){
            if(j == N)continue;
            sum[j]++;
        }
    }
    vector<pair<double,int>> fail(N);
    
    for(int i = 0; i < N; i++){
        if(sum[i] == 0)fail[i].first = 0;
        else
        fail[i].first = double(ch[i]) / double(sum[i]);
        fail[i].second = i+1;
        cout<<fail[i].first<<" " << fail[i].second<<endl;
    }
    sort(fail.begin(),fail.end(),compare);
    
    for(int i = 0; i < N; i++){
        answer.push_back(fail[i].second);
    }
    
    
    return answer;
}