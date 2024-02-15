#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    int m = 1 << n;
    
    
    for(int i = 0; i < n; i++){
        string s;
        int x = arr1[i];
        int y = arr2[i];
        
        int z = x | y;
        if(z >= m) z -= m;
        
       for(int i = 0; i<n;i++){
            int cur = z & 1;
            z = z >> 1;
            if(cur == 1){
                s = "#" + s;
            }else{
                s = " " + s;
            }
        }
       
        answer.push_back(s);
    }

    
    return answer;
}