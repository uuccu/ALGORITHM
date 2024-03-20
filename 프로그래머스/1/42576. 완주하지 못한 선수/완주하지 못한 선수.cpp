#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> p, vector<string> c) {
    string answer = "";
    map<string,int> s;
    for(auto x: p)s[x]++;
    for(auto x: c)s[x]--;
    
    
    for(auto x: s){
        if(x.second != 0)return x.first;
    }
    
    return answer;
}