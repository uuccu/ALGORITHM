#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    int len = 5;
    for(int i = 0; i<word.size();i++){
        int x = word[i];
        int diff = len - i - 1;
        int a = 1;
        int b = 1;
        for(int j = 0 ; j < diff; j++){
            b *= 5;
            a += b;
        }
        
        if(x == 'A'){
            answer += 1;
        }if(x == 'E'){
            answer +=  a + 1;
        }if(x == 'I'){
            answer += 2 * a + 1;
        }if(x == 'O'){
            answer += 3 * a + 1;
        }if(x == 'U'){
            answer += 4 * a + 1;
        }
    }
    
    
    return answer;
}