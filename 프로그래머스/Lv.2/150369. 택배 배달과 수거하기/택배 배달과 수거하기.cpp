#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


long long solution(int c, int n, vector<int> d, vector<int> p) {
    long long answer = 0;

    int dcur = 0;
    int cnt = 0;
    int pcur = 0;

    for (int i = n - 1; i >= 0; i--) {

        dcur -= d[i];
        pcur -= p[i];

        while(1){
            if(dcur >=0 && pcur >= 0)break;
            dcur += c;
            pcur += c;
            cnt++;
        }

        answer += (i+1) * 2 * cnt;
        cnt = 0;
    }


    return answer;
}