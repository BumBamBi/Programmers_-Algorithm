#include <string>
#include <vector>
#include <math.h>

using namespace std;

// 문자열 _s를 _n개 만큼 잘라서 압축
int cal_len(string _s, int _n){
    
    // 결과값을 저장할 ans 선언
    string ans = "";
    
    // 반복 횟수를 저장할 cnt 선언
    int cnt = 1;
    
    // 이전에 자른 문자열을 저장하는 before_str 선언
    // _s을 처음부터 _n개까지 자른 값을 대입
    string before_str = _s.substr(0,_n);
    
    // 현재 자른 문자열을 저장할 current_str 선언
    string current_str = "";
    
    // _n개부터 _n개씩 더하면서 반복하도록 함.
    // 함수 진입 for문에 의해 _n < _s.length()이므로 _s.length()-1 까지만 반복
    for(int i=_n; i<_s.length(); i+=_n){
        
        // _s를 i부터 _n개 잘라낸 문자열을 current_str에 저장
        current_str = _s.substr(i,_n);
        
        if(current_str == before_str){
            // 현재 두 문자열이 반복된다면, cnt + 1
            cnt += 1;
        }else{
            // 현재 두 문자열이 반복되지 않는다면,
            if(cnt == 1){
                // 해당 문자열(before_str)이 한번도 반복된적 없으면
                // 직전 문자열(before_str)만 ans에 붙여넣음
                ans += before_str;
            }else{
                // 한번 이상 반복된적 있다면,
                // 반복횟수(cnt)와 반복되었던 문자열(before_str)을 ans에 붙여넣음
                ans += to_string(cnt);
                ans += before_str;
                
                // 반복 횟수를 1로 초기화
                cnt = 1;
            }
        }
        
        // 이전에 잘라낸 문자열(before_str)을 현재 잘라낸 문자열(current_str)로 초기화
        before_str = current_str;
    }
    
    // 마지막에 남은 문자열이 2회 이상 반복되었다면 cnt 출력
    // 반복되지 않았다면 그냥 출력하는 것이 더 짧음
    // aabbab = 2a2bab vs 2a2b1ab
    if(cnt != 1){
        ans += to_string(cnt);
    }
    ans += current_str;

    // ans의 길이만큼 리턴
    return ans.length();
}

int solution(string s) {
    
    // 압축이 하나도 되지 않을 경우는 기존 문자열이 제일 짧음
    int min_length = s.length();
    
    // 기존 문자열 == 문자열 길이만큼 잘라서 압축 == 압축이 되지 않음
    // 따라서 s.length()-1 까지만 반복
    for(int i=1; i<s.length(); i++){
        // cal_len(string, i) 는 문자열 s를 i개씩 잘라서 압축하면 나오는 문자열 길이를 리턴.
        // cal_len의 결과와 이전 min_length와 작은것을 남김
        min_length = min(min_length, cal_len(s, i));
    }
    return min_length;
}