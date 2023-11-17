#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> parent;// 자식-부모
unordered_map<string, int> profit;// 사람 - 최종수익이 들어갈예정

void recursive(string name, int money){
    int tmp = money * 0.1;
    
    profit[name] += money - tmp;
    if(tmp < 1)return;
    if(parent[name] =="center")return;
    
    recursive(parent[name], tmp);
}


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    // 세그먼트 트리인줄 알고 골랐는데 아니었다.
    vector<int> answer;
    
    for (int i = 0; i < enroll.size(); ++i) {
        if (referral[i] == "-") parent[enroll[i]] = "center"; 
        else parent[enroll[i]] = referral[i];
    }
    
    for (int i = 0; i < amount.size(); i++) {
        // 개당 100원이므로 100 곱하기.
        amount[i] = amount[i] * 100;
    }
    
    for (int i = 0; i < seller.size(); i++){
        // 이익을 업데이트 시키기. 재귀를 통해 부모로 계속 타고올라가면서 수익의 10퍼센트를 전달하면됨
        
        // leaf node로 풀어야 하나 싶었다. 따라서 leaf node을 판단할려고 in_degree을 할려고했지만
        // 하다보니 그럴 필요가 없다.
        
        // (누적)profit에서 10프로 때는식이 아닌
        // 인자로 추가될 양을 보여주면 될거같다.
        
        //그래서 판매자들의 수익이 날때마다 재귀를 돌려주자
        
        recursive(seller[i],amount[i]);   
    }
    
    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(profit[enroll[i]]);//순서대로 profit을 설정한 값을 집어넣으면 된다.

    return answer;
}