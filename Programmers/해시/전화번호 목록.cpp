#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    
    unordered_map<string, int> mymap;
    
    for(auto& e:phone_book){
        mymap.insert(make_pair(e, 1));
    }
    
    bool answer = true;
    int len = 0;
    
    for(auto& e:phone_book){
        len = e.length();
        for(int i=1; i<len; i++){
            // 문자열을 하나씩 줄여보면서 접두어가 있는지 확인
            if(mymap.find(e.substr(0,len-i)) != mymap.end()){
                // 접두어가 있으면 false
                answer = false;
                return answer;
            }
        }
    }
    
    answer = true;
    return answer;
}