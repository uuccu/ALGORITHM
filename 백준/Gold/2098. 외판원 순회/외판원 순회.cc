#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, j) for(ll i=0;i<j;i++)
#define mrep(i,j,k) for(ll i = j; i<=k;i++)
#define drep(i,j,k) for(ll i = j; i>=k; i--)
#define pb push_back
#define pf push_front
#define pll pair<long long, long long>
#define pii pair<int,int>
#define vpll vector<pair<long long,long long>>
#define ff first
#define ss second
#define YES "YES"
#define NO "NO"
typedef long long ll;

const int MAXN = 510;
const int MAXINT = 2147483098;
const int inf = 1e9 + 7;
//const ll MAXLL = 9223372036854775258LL;
//bool comp(pii & a, pii & b) {
//	if (a.ff == b.ff) {
//		return a.ss < b.ss;
//	}
//	return a.ff < b.ff;
//	//    if(a.ff.ff == b.ff.ff)return a.ff.ss < b.ff.ss;
//	//    return a.ff.ff < b.ff.ff;
//}
////sort compare > == decending < == incresing

ll n;
ll path[17][17];
vector<vector<ll>> dp;
ll find_path(ll end, ll visited) {
	ll all_visited = (1 << n) - 1;
	if (visited == all_visited && path[end][1]) {
		return path[end][1];
	}
	if (dp[end][visited] != -1) {
		return dp[end][visited];
	}
	ll tmp = inf;
	rep(next, n) {
		if (!path[end][next + 1] || (visited & (1 << next)))continue;//path가 0 이거나 이미 방문을 한 곳이라면 skip을 한다. 
		tmp = min(tmp, find_path(next+1, (visited | (1 << next))) + path[end][next+1]);
	}
	dp[end][visited] = tmp;
	return tmp;
}

void solve() {
	dp = vector<vector<ll>>(17, vector<ll>(65537, -1));	
	cin >> n;
	rep(i, n) {
		rep(j, n) {
			cin >> path[i + 1][j + 1];
		}
	}
	cout<<find_path(1,1);
}

int main() {
	//#ifndef ONLINE_JUDGE
	//    freopen("input.txt", "r", stdin);
	//#endif
	fast_io;
	//    cout << fixed;
	//    cout.precision(10);
	/*int t;
	cin >> t;
	rep(i, t)*/
	solve();
	//    cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "S\N";
	return 0;
}