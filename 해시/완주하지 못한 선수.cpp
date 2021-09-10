#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    
    set<string> myset;
    
    for(auto& e:phone_book){
        // 모든 번호를 set에 저장
        myset.insert(e);
    }
    
    bool answer = true;
    int len = 0;
    
    for(auto& e:phone_book){
        len = e.length();
        
        // (문자열의 길이-1) 부터 반복하면서, 자기 자신 문자열의 일부가 set에 있는지 확인(접두어인지 확인)
        for(int i=1; i<len; i++){
            if(myset.find(e.substr(0,len-i)) != myset.end()){
                // 있으면 false
                answer = false;
                return answer;
            }
        }
    }
    // 없으면 true
    return answer;
}