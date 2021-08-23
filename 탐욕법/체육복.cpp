#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    // 학생수만큼 벡터 생성 및 1로 초기화
    vector<int> v(n, 1);
    
    // 체육복을 잃어버린 학생의 해당 index에 -1
    for(auto e:lost){
        v[e-1] -= 1;
    }
    
    // 체육복을 더 챙겨온 학생의 해당 index에 +1
    for(auto e:reserve){
        v[e-1] += 1;
    }
    
    // 체육복이 0개인 학생의 앞 뒤에 체육복을 2개 가진 학생이 있다면 나눠받음
    // v[] 경우 범위 검사x, 범위 초과시 0으로 나옴 -> == 2 의 경우에 해당 되지 않음으로 문제 없음(v.at()은 범위 검사 함)
    for(int i=0; i<v.size(); i++){
        if(v[i] == 0){
            // 앞 학생이 체육복을 2개 가지고 있는 경우
            if(v[i-1] == 2){
                v[i-1] -= 1;
                v[i] += 1;
            }
            // 뒤 학생이 체육복을 2개 가지고 있는 경우
            else if(v[i+1] == 2){
                v[i+1] -= 1;
                v[i] += 1;
            }
        }
    }
    
    int answer = 0;
    
    // 체육복이 1개 이상인 경우 +1
    for(auto e:v){
        if(e >= 1){
            answer += 1;
        }
    }

    return answer;
}