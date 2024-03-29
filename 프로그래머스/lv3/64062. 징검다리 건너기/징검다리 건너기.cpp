#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool canCross(vector<int>& stones, int mid, int k){// 건널수있는지 판단
    int emptyBlock = 0;
    for(int i = 0; i<stones.size(); i++){
        if(stones[i]<=mid) emptyBlock++; //건너뛰는 수
        else emptyBlock = 0; // 중간에 끊기면 초기화
        if(emptyBlock>=k) return false; //못건너뛰면 true
    }
    return true;//건너뛰기 가능
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int begin = 1;
    int end = 200000000;
    
    while(begin <= end){
        int mid = (begin + end)/2;
        //mid만큼의 사람이 건널수 있는가 없는가를 판단.
    
        if(!canCross(stones,mid,k)){
            end = mid -1;
        }else{
            begin = mid + 1;
        }
    }
    
    
    return begin;
}