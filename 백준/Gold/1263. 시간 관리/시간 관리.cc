#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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


vector<pair<int, int>> vp;// 끝내야 할 시간, 걸리는 시간

bool inTime(int t){// t시간에 가능하면
    int cur = t;
    for(auto & i : vp){
        if(cur + i.second > i.first)return false;
        cur += i.second;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {// 입력받기.
        int x, y;
        cin >> x >> y;
        vp.emplace_back(y, x);
    }
    sort(vp.begin(), vp.end());


    int left = 0;
    int right = 1000 * 1000000;
    int answer = -1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if (inTime(mid)) {// 해당 시간내에 가능한 경우
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout<<answer;
}