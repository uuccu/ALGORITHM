#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
const int MAX = 2e9;
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i = 0; i < balls.size(); i++){
        int x = balls[i][0];
        int y = balls[i][1];
        
        // x,y와 startX startY의 차이
        int diffX = abs(x - startX);
        int diffY = abs(y - startY);
        
        cout<<diffX<<" "<<diffY<<endl;
        
        // x,y와 startX startY의 합
        int sumX = x + startX < m ? x + startX : 2*m - x - startX;
        int sumY = y + startY < n ? y + startY : 2*n - y - startY;
        cout<<sumX<<" "<<sumY<<endl;
        
        int left = pow(sumX,2) + pow(diffY,2);
        int right = pow(sumY,2) + pow(diffX,2);
        // 같은 선상에 있을시에 먼저 부딪히는 경우 제외시키기. 
        
        // 같은 x 선상에 있는 경우
        if(startX == x && startY > y && startY + y < n )right = MAX;
        if(startX == x && startY < y && startY + y > n )right = MAX;
        
        // 같은 y 선상에 있는 경우
        // 이게 예제 2번임
        if(startY == y && startX > x && startX + x < m)left = MAX;
        if(startY == y && startX < x && startX + x > m )left = MAX;
        int minDistance = min(left , right);
        //꼭짓점에 튕기는 경우
        if(startX == startY && x == y){
            minDistance = min(minDistance, int(pow(x,2) + pow(y,2)));
        }        
        cout<<minDistance<<endl;
        
        if(startX==x) {
            if(startY>y) minDistance = min(minDistance, (2*n-startY-y)*(2*n-startY-y));
            else minDistance = min(minDistance, (startY+y)*(startY+y));
        }
        if(startY==y){
            if(startX>x) minDistance = min(minDistance, (2*m-startX-x)*(2*m-startX-x));
            else minDistance = min(minDistance, (startX+x)*(startX+x));
        }
        answer.push_back(minDistance);        
    }
    return answer;
}