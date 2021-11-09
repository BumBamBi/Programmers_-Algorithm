#include <string>
#include <vector>

using namespace std;

// 전역변수로 answer을 미리 선언
int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int count){
    // numbers의 모든 요소에 접근했을 때
    if(count == numbers.size()){
        // 그 값이 target과 같다면
        if(sum == target){
            answer +=1 ;
        }
        return;
    }else{
        // 현재 numbers의 요소를 + 할 경우
        dfs(numbers, target, sum + numbers[count], count + 1);
        // 현재 numbers의 요소를 - 할 경우
        dfs(numbers, target, sum - numbers[count], count + 1);
    }
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}