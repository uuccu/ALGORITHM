#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<bool> v(30,false);
    
    for(int i = 0; i < 28; i++){
        int x; 
        cin>>x;
        v[x-1] = true;
    }
    int i = 1;
    for(auto x: v){
        if(x == false)cout<<i<<endl;
        i++;
    }
    

    
}



