#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool comp(string x, string y) {
    string tmp1 = x + y;
    string tmp2 = y + x;
    return tmp1 > tmp2;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(auto x: numbers){
        v.push_back(to_string(x));
    }
    sort(v.begin(),v.end(),comp);
    
    for(auto x: v){
        if(answer == "" && x == "0"){
            continue;
        }
        answer += x;
    }
    if(answer =="")answer = "0";
    
    return answer;
}