#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
    
int max_cnt = 0;
int max_value = 0; // max_cnt가 수정되면 애를 동기화 시켜야함. 

int discounts[] = {10,20,30,40};
vector<int> arr;

void dfs(vector<vector<int>>& users, vector<int>& emoticons){
    if(arr.size() == emoticons.size()){
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i<users.size(); i++){
            int prop = users[i][0];
            int price = users[i][1];
            int temp = 0;
            for(int j = 0; j < emoticons.size(); j++){
                if(prop > arr[j])
                    continue;
                temp += (emoticons[j] * (100 - arr[j]) * 0.01);
            }
            if(temp < price)sum+= temp;
            else cnt++;
        }
        // cout<<cnt<<" "<<sum<<" "<<max_cnt<<" "<<max_value<<endl;
        if(max_cnt <= cnt){
            if(max_cnt < cnt) max_value = sum;
            else if(max_cnt == cnt) max_value = max(max_value,sum);
            max_cnt = cnt;
        }        
        
        return;
    }
    for(int i = 0; i < 4; i++){
        arr.push_back(discounts[i]);
        dfs(users,emoticons);
        arr.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    //( 10 20 30 40 ) * ( 7 ) * ( 100 )
    dfs(users,emoticons);
    answer.push_back(max_cnt);
    answer.push_back(max_value);

    return answer;
}