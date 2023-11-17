#include <bits/stdc++.h>

using namespace std;
string toK(int n, int k){
    int cur = n;
    string s = "";
    while(cur){
        int mod = cur % k;
        s += to_string(mod);
        cur = cur / k;
    }
    return string(s.rbegin(),s.rend());
}

bool isPrime(long long n){
    if(n < 2) return false;
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }       
    return true;   
}

int solution(int n, int k) {
    int answer = 0;
    string s = toK(n,k);
    
    string sNum = "";
    
    for(int i = 0; i <s.size(); i++){
        if(s[i] == '0' && sNum != ""){
            long long num = stoll(sNum);
            if(isPrime(num))answer++;
            sNum ="";
        }else{
            sNum += s[i];
        }      
    }
    if(sNum != ""){
        long long num = stoll(sNum);
        if(isPrime(num))answer++;
    }   
    return answer;
}





