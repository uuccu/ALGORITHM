#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

//int n,m;
//int main() {
//    cin>>n>>m;
//
//    vector<string> nstr;
//    vector<string> mstr;
//    string s;
//
//    for(int i = 0; i< n; i++){
//        cin>>s;
//        nstr.push_back(s);
//    }
//
//    for(int i = 0; i< m; i++){
//        cin>>s;
//        mstr.push_back(s);
//    }
//    int cnt = 0;
//    bool isC;
//    for(auto &x: mstr){
//        isC = true;
//        for(auto &y:nstr){
//            if(x.size() > y.size())continue;
//            for(int i =0; i < y.size(); i++){//x의 사이즈가 같거나 작다.
//                if(x.size() <= i){
//                    cnt++;
//                    isC = false;
//                    break;
//                }
//                if(x[i] != y[i])break;
//            }
//            if(!isC)break;
//        }
//    }
//
//    cout<<cnt;
//}

int main() {
    int n;
    cin>>n;
    map<int,int> s;
    vector<int> v(n);

    int zeroCnt = 0;
    for(auto &x: v){
        cin>>x;
        if(x == 0)zeroCnt++;
        if(s.find(x) != s.end()){
            s[x]++;
        }else{
            s.insert({x,1});
        }

    }

    map<int,int> ans;
    for(int i = 0; i< v.size(); i++){
        for(int j = i + 1; j< v.size(); j++){
            int sum = v[i] + v[j];
            if(zeroCnt <= 2 ){
                if(v[i] ==0 && v[j] == 0)continue;
                if(v[i] == 0){
                    if(s[v[j]] <= 1 )continue;
                }if(v[j] == 0){
                    if(s[v[i]]<=1)continue;
                }
            }
            if(s.find(sum) != s.end()){
                ans.insert({sum,s[sum]});
            }
        }
    }
    int cnt = 0;
    for(auto & an : ans){
        cnt += an.second;
    }
    cout<<cnt;
}