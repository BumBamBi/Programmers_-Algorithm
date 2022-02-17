#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    bool isSelected[people.size()];
    
    for(int i=0; i<people.size(); i++){
        isSelected[i] = false;
    }
    
    sort(people.begin(), people.end());

    int N = people.size();
    int first_idx = 0;
    int last_idx = N-1;
    int savedCnt = 0;
    
    while(savedCnt < N){
        // 현재 가장 무거운 사람의 무게가 절반 이하라면
        if (people[last_idx] <= limit / 2) {
            // 두명씩 무조건 탈 수 있으니, 남은사람/2 개만큼 필요
            answer += ceil(float(last_idx + 1 - first_idx) / 2);
            break;
        }
        
        if(people[first_idx] +people[last_idx] <= limit){
            first_idx++;
            last_idx--;
            answer++;
            savedCnt += 2;
            continue;
        }else{
            last_idx--;
            answer++;
            savedCnt++;
        }
        
    }
    
    return answer;
}