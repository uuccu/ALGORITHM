#include<bits/stdc++.h>


using namespace std;
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i, j) for(ll i=0;i<j;i++)
#define mrep(i, j, k) for(ll i = j; i<=k;i++)
#define drep(i, j, k) for(ll i = j; i>=k; i--)
#define pb push_back
#define pf push_front
#define pll pair<long long, long long>
#define pii pair<int,int>
#define vpll vector<pair<long long,long long>>
#define vll vector<long long>
#define ff first
#define ss second
#define YES "YES"
#define NO "NO"
#define yes "YES"
#define no "NO"
typedef long long ll;

const int MAXN = 510;
const int MAXINT = 2147483098;
const int inf = 1e9 + 7;
const int MOD = 1e9;
//const ll MAXLL = 9223372036854775258LL;
//bool comp(pair<int,pii>& a, pair<int,pii> & b) {
//	if (a.ff == b.ff) {
//		return a.ss < b.ss;
//	}
//	return a.ff > b.ff;
//}
//struct comp{
//    bool operator()(pair<int,pii> a, pair<int,pii> b){
//        if(a.ff == b.ff){
//            return a.ss > b.ss;
//        }
//        return a.ff > b.ff;
//    }
//};

////sort compare > == decending < == incresing
int n, k;

int dp[1001];

int recursive(int n) {
    if (n < 1) return 0;
    if (n < 2) return 1;

    int &cur = dp[n];
    if (cur != -1) return cur;

    cur = 1;
    for (int i = 1; i <= n / 2; i++) {
        cur += recursive(i);
    }
    return cur;
}


void solve(int testcase) {
    int m;
    cin >> m;
    cout << recursive(m) << endl;
}

int main() {
    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //#endif
    fast_io;
//    cout << fixed;
//    cout.precision(6);
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    rep(i, t)solve(i);

//    solve(1);
    //    cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "S\N";
    return 0;
}
