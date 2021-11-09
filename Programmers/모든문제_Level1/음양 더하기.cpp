#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    // 총 개수만큼 반복
    for(int i=0; i<absolutes.size(); i++){
        // 부호에 따른 연산 수행
        if(signs[i]){
            answer += absolutes[i];
        }else{
            answer -= absolutes[i];
        }
    }
    return answer;
}