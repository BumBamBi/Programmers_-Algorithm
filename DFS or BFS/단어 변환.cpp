#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 초기값을 크게 줘서 min으로 최소경로 찾기
int answer = 9999;

// 한글자만 달라서 변환할 수 있는 함수
bool canchange(string std, string another){
    int diff_cnt = 0;
    
    for(int i=0; i<std.size(); i++){
        if(std[i] != another[i]){
            diff_cnt += 1;
            if(diff_cnt > 1){
                return false;
            }
        }
    }
    
    if(diff_cnt == 1){
        return true;
    }else{
        return false;
    }
}

// 현재 단어가 words의 몇번째 인덱스인지 알려주는 함수
int findindex(string s, vector<string> words){
    auto iter = find(words.begin(), words.end(), s);
    
    return (iter - words.begin());
}

// 방문했는지 확인해주는 함수
bool isvisited(int n, string visited){
    for(auto e:visited){
        if(e == (n + '0')){
            return true;
        }
    }
    return false;
}

void dfs(string cur, string target, vector<string> words, string visited, int cnt){
    // 도착점에 도착한 경우
    if(cur == target){
        answer = min(answer, cnt);
        return;
    }
    // 도착점에 도착하지 않은 경우
    else{
        // 방문한 적 있음으로 체크
        int cur_index = findindex(cur, words);
        visited += to_string(cur_index);
        
        for(int i=0; i<words.size(); i++){
            // 변환할 수 있는 단어 중
            if(canchange(cur, words[i]) == true){
                int will_visit_index = findindex(words[i], words);
                // 방문한 적 없는 단어로 변경
                if(isvisited(will_visit_index, visited) == false){
                    dfs(words[i], target, words, visited, cnt+1);
                }
            }
        }
        return;
    }
}

int solution(string begin, string target, vector<string> words) {
   
    for(int i=0; i<words.size(); i++){
        if(canchange(begin, words[i]) == true){
            dfs(words[i], target, words, "", 1);
        }
    }
    
    // 변환할 수 없는 경우
    if(answer == 9999){
        return 0;
    }else{
        return answer;
    }
}