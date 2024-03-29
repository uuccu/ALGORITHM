#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool compare(const int & x, const int & y){
    if( x > y ){
        return true;
    }else {
        return false;
    }
}


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<int> newM;
    
    int cnt = 0;
    
    int size = minerals.size() < (picks[0] + picks[1] + picks[2]) * 5 
        ? minerals.size() :(picks[0] + picks[1] + picks[2]) * 5;
    ;
    
    
    for(int i =0; i < size; i++){       
        if(minerals[i] == "diamond"){
            cnt += 100;
        }else if(minerals[i] == "iron"){
            cnt += 10;
        }else{
            cnt += 1;
        }
        if((i % 5 == 4 && i != 0)|| i == size - 1 ){
            newM.push_back(cnt);
            cnt = 0;
        }        
    }    
    sort(newM.begin(), newM.end(), compare);
    
    for(auto &x: newM){
        int dia = 0, iron = 0, stone = 0;
        dia = x / 100;
        iron = (x % 100)/10;
        stone = x % 10;
        cout<< x <<endl;
        
        if(picks[0] > 0){
            picks[0] -= 1;
            answer += dia + iron + stone;
        }else if(picks[1] > 0){
            picks[1] -=1;
            answer += dia * 5  + iron + stone;
        }else if(picks[2] > 0){
            picks[2] -=1;
            answer += dia * 25 + iron * 5 + stone;
        }
    }
    
    return answer;
}