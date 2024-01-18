#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//공백 기준으로 split 하기 위한 간단한 함수 구현
vector<string> split(string s, char ch){
    vector<string> temp_string;
    int idx = s.find(ch);
    temp_string.push_back(s.substr(0,idx));
    temp_string.push_back(s.substr(idx));

    return temp_string;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> temp_answer;
    unordered_map<string, unordered_set<string>> who_report;
    unordered_map<string, int> reported_count;
    unordered_map<string, int>::iterator count_it;

    // 이름 기준으로 answer 을 채워주기 위해 temp_answer 생성
    for(string id : id_list){
        temp_answer.push_back(id);
        answer.push_back(0);
    }

    // (신고한 사람 : 신고 당한 사람들) 형식으로 unordered_map 생성
    // 신고 당한 사람들을 unordered_set 으로 한 것은 중복 제거
    for(string name : report){
        who_report[split(name, ' ')[0]].insert(split(name, ' ')[1]);
    }

    // (신고 당한 사람 : 신고 당한 횟수) 형식으로 unordered_map 생성
    for(auto it = who_report.begin(); it != who_report.end(); it++){
        for(auto iter = (it->second).begin(); iter != (it->second).end(); iter++) {
            reported_count[*(iter)] += 1;
        }
    }

    // (신고 당한 사람 : 신고 당한 횟수) 에서 k 보다 적게 신고 당한 사람들은 제거
    for(count_it = reported_count.begin();  count_it != reported_count.end(); ) {
        if (count_it->second < k) {
            count_it = reported_count.erase(count_it);
        }
        else {
            count_it++;
        }
    }

    // k 번 이상 신고 당한 사람들의 이름이 (신고한 사람 : 신고 당한 사람들) 의 [신고 당한 사람들] 안에 있다면
    // temp_answer 에서 해당 사람을 신고한 신고자의 이름을 찾고 그 이름의 index 를 answer 에서 +1 해준다
    for(pair<string, unordered_set<string>> who_name : who_report){
        for(string who_reported : who_name.second){
            for(pair<string, int> reported : reported_count){  
                if(reported.first == who_reported){
                    answer[find(temp_answer.begin(), temp_answer.end(), who_name.first)-temp_answer.begin()] += 1;
                }
            }   
        }
    }
    return answer;
}