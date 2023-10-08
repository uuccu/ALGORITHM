#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> board) {
    int ocnt = 0, xcnt = 0;
    int winX = 0; 
    int winO = 0;
    for(int i =0; i<3; i++){// 가로세로 체크
        if(board[i] == "OOO")
            winO++;
        if(board[i] == "XXX")
            winX++;
        if(board[0][i]  == 'O' &&  board[1][i] == 'O' && board[2][i] == 'O')
            winO++;
        if(board[0][i]  == 'X' &&  board[1][i] == 'X' && board[2][i] == 'X')
            winX++;
    }
    if(board[0][0]  == 'X' &&  board[1][1] == 'X' && board[2][2] == 'X')// 대각선 체크
            winX++;
    if(board[0][0]  == 'O' &&  board[1][1] == 'O' && board[2][2] == 'O')
            winO++;
    if(board[0][2]  == 'X' &&  board[1][1] == 'X' && board[2][0] == 'X')
            winX++;
    if(board[0][2]  == 'O' &&  board[1][1] == 'O' && board[2][0] == 'O')
            winO++;
    
    
    
    for(int i = 0; i< 3; i++){
        for(int j = 0; j<3; j++){
            if(board[i][j] == 'O'){// 개수 세기
                ocnt++;
            }else if(board[i][j] == 'X'){
                xcnt++;
            }
        }
    }
    if(xcnt + ocnt == 0)return 1;
    if(ocnt > xcnt + 1)return 0;//x가 o를 하나 없애고 x로 만들어도 1보다 차이나면안됨
    if(ocnt < xcnt)return 0;// o의 개수가 x보다 
    
    if(winX == 0&& winO == 0)return 1;
    if((winX == 0 &&winO>0&&xcnt <ocnt) )return 1;
    if(winX > 0 &&winO==0&&xcnt ==ocnt)return 1;
    return 0;
}