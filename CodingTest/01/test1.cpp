#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <math.h>

using namespace std;

bool isAvailable(vector<char> v){
    int len = v.size();

    for (int i = 0; i < v.size() / 2; i++){
        // 좌우를 하나씩 비교해서 다르다면
        if(v[i] != v[(len-1)-i]){
            return false;
        }
    }
    return true;
}

int solution(vector<string> s) {
    int ans = -1;
    for(auto &str : s){
        // 각 문자열을 저장할 벡터
        vector<char> vecChar;
        vector<char> vecNum;
        vector<char> vecSpecial;
        
        // 모든 문자에 접근
        for (int i = 0; i < str.size(); i++){
            // 소문자면 대문자로 변환
            if(str[i] >= 'a' && str[i] <= 'z'){
                str[i] -= 32;
            }

            // 알파벳이면
            if(str[i] >= 'A' && str[i] <= 'Z'){
                vecChar.push_back(str[i]);
            }
            // 숫자면
            else if(str[i] >= '0' && str[i] <= '9'){
                vecNum.push_back(str[i]);
            }
            // 특수문자면
            else{
                vecSpecial.push_back(str[i]);
            }
        }

        // 각 벡터가 팰리드롬인지 확인하여
        if(isAvailable(vecChar) && isAvailable(vecNum) && isAvailable(vecSpecial)){
            // 모두 팰리드롬이면, 최대 문자열 계산
            ans = max(ans, (int)str.size());
        }
    }
    if(ans == -1){
        return 0;
    }else{
        return ans;
    }
}

int main(){
    vector<string> input;

    input.push_back("!@ab12cCbA21@!!!!!");
    input.push_back("!@ab12cCbA21@!");
    input.push_back("ab12cCbA21");

    cout << solution(input);
}