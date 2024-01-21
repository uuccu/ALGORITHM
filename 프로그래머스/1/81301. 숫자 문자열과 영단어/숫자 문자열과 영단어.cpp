#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string word[10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i<s.size();i++){
        char c = s[i];
        int num = c - '0';
           if(c == 'z'){
              num = 0;
              i += 3;
           }else if(c == 'o'){
              num = 1;
              i += 2;
           }else if(c == 't'){
               if(s[i+1] == 'w'){
                   num = 2;
                   i += 2;
               }else{
                   num = 3;
                   i += 4;
               }
           }else if(c =='f'){
               if(s[i+1] == 'i'){
                   num = 5;
               }else{
                   num = 4;
               }
               i+=3;
               
           }else if(c =='s'){
               if(s[i+1] == 'i'){
                   num = 6;
                   i+=2;
               }else{
                   num = 7;
                   i+=4;
               }
               
           }else if(c =='e'){
               num = 8;
               i+=4;
           }else if(c =='n'){
               num = 9;
               i += 3;
           }
            answer = answer * 10 + num;
        
    }
    
    
    
    
    
    
    return answer;
}