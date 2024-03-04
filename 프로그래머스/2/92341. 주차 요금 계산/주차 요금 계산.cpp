#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int cal_time(string s){
    int answer = 0;
    
    
    char h1 = s[0];
    char h2 = s[1];
    char m1 = s[3];
    char m2 = s[4];
    
    answer += (h1 - '0') *10 * 60;
    answer += (h2 - '0') * 60;
    answer += (m1-'0') * 10;
    answer += (m2-'0');

    
    return answer;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, vector<int>> m;
    stringstream ss;
    
    int dt = fees[0];
    int df = fees[1];
    int pt = fees[2];
    int pf = fees[3];
    
    for(auto x: records){
        ss.str(x);
        string time, number, status;
        ss >> time >> number >> status;
        
        int num = cal_time(time);
        
        m[number].push_back(num);
        ss.clear();
    }

    for(auto x: m){
        if(x.second.size() % 2 == 1){
            x.second.push_back(cal_time("23:59"));
        }
        
        
        int cost = df;
        int diff = 0;
        cout<< x.first<< " ";
        for(int i = 0; i < x.second.size(); i += 2){
            int in = x.second[i];
            int out = x.second[i+1];
            
             diff += out - in;
        }
        diff -= dt;
        if(diff > 0){
                int cnt = diff / pt;
                if(diff % pt != 0)cnt++;
                cost += cnt * pf;
            }
        cout<<endl;
        answer.push_back(cost);
    }
    
    return answer;
}