#include <bits/stdc++.h>
using namespace std;
//ch는 알파벳에 해당하는 숫자 저장,
//num에는 0~9가 쓰였는지 저장 
int ch[30] , num[10], cnt=0;

string a, b, c;
map<char, int> m;
bool flag; 


void DFS(int cur, int end){
	if(flag) return;
	if(cur==end){
		int i,send=0,more=0, money=0;
		for(i=0; i<a.length(); i++){
			send = send*10 + ch[m[a[i]]];
		}
		for(i=0; i<b.length(); i++){
			more = more*10 + ch[m[b[i]]];
		}
		for(i=0; i<c.length(); i++){
			money = money*10 + ch[m[c[i]]];
		}
		if((send+more)==money){ 
			flag=true;
//			cnt++;
//			cout << cnt << "번------"<<'\n';
//			
//			cout<<send<<'\n';
//			cout<<more<<'\n';
//			cout<<money<<'\n';
//			cout<<"----------------"<<'\n';
		}
		
		return;
	}
	else{		
		for(int i=0; i<=9;i++){
			if(num[i]==0){
				num[i]=1;
				ch[cur] = i;
				DFS(cur+1, end);
				num[i]=0;
			}
		}
	}
}



int main(){
	//freopen("input.txt.txt","rt",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,node=0;
	cin >> a >> b >> c;

	
	for(i=0; i<a.length(); i++){
		if(m.count(a[i])==0) m[a[i]]=node++;
	}
	for(i=0; i<b.length(); i++){
		if(m.count(b[i])==0) m[b[i]]=node++;
	}
	for(i=0; i<c.length(); i++){
		if(m.count(c[i])==0) m[c[i]]=node++;
	}
	
	DFS(0,node);
	
	if(flag) cout << "YES\n";
	else cout << "NO\n";

}