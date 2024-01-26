#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


string solution(string new_id) {
    string answer = "";
    
    for(auto &c : new_id) {
        if(c >= 'A' && c<='Z') c = 'a' + c - 'A';
    }
    
    regex re("[^a-z0-9._-]");
    new_id = regex_replace(new_id,re,"");
    
    regex re1("\\.+");
    new_id = regex_replace(new_id, re1, ".");
    
    if(new_id[0] == '.') new_id.erase(new_id.begin());
    if(new_id.back() == '.') new_id.pop_back();
    
    if(new_id.empty())new_id = "a";
    
    if(new_id.size() > 15)  new_id = new_id.substr(0, 15);
    if(new_id.back() == '.')    new_id.pop_back();
    
    while(new_id.size() <= 2)
        new_id.push_back(new_id.back());
    
    answer = new_id;
    
    
    return answer;
}