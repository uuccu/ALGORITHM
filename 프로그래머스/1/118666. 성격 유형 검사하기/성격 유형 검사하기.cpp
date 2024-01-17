#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    int arr[4] = {0,0,0,0};
    char left[4] = {'R','C','J','A'};
    char right[4] = {'T','F','M','N'};
    string answer = "";
    for(int i = 0; i < survey.size();i++){
        char a = survey[i][0];
        char b = survey[i][1];
        int choice =  choices[i];
        
        if(a == 'R'){
            arr[0] += 4 - choice;
        }else if(a == 'T'){
            arr[0] += choice - 4;
        }else if(a == 'C'){
            arr[1] += 4 - choice;
        }else if(a == 'F'){
            arr[1] += choice - 4;
        }else if(a == 'J'){
            arr[2] += 4 - choice;
        }else if(a == 'M'){
            arr[2] += choice - 4;
        }else if(a == 'A'){
            arr[3] += 4 - choice;
        }else if(a == 'N'){
            arr[3] += choice - 4;
        }
    }
    for(int i =0; i<4; i++){
        if(arr[i] >= 0){
            answer += left[i];
        }else{
            answer += right[i];
        }
    }

    return answer;
}