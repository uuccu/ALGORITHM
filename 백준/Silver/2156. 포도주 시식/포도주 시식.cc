#include <iostream>
#include <cstring>
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
int dp[10001];

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);

    for(auto &x: arr)cin>>x;
    memset(dp,-1,sizeof(dp));
    if(n == 1){
        cout<<arr[0];
    }else if(n==2){
        cout<< arr[0] + arr[1];
    }else{
        dp[0] = arr[0];
        dp[1] = arr[0] + arr[1];
        dp[2] = max(arr[0]+arr[1],max(arr[0] + arr[2], arr[1]+ arr[2]));
        

        for(int i = 3; i < n; i++){
            int tmp = max(dp[i-3] + arr[i] + arr[i -1], dp[i-2] + arr[i]);
            dp[i] = max(dp[i-1],tmp);
        }
        cout<<dp[n-1];
    }
    return 0;
}