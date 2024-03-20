#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> pb) {
    bool answer = true;
    set<string> s;
    
    for(auto x: pb)s.insert(x);
    
    
    for(auto x: pb){
        if(x.size() == 1){
            s.erase(x);
            if(s.find(x) != s.end()){
                return false;
            }
            s.insert(x);
        }
        for(int i = 1; i < x.size();i++){
            string tmp = x.substr(0,i);
            // cout<<tmp<<" ";
            if(s.find(tmp) != s.end()){
                // cout<<tmp;
                return false;
            }
        }
        
    }
    return true;
}