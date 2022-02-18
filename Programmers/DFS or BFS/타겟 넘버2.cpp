#include <string>
#include <vector>

using namespace std;

int SIZE;
int answer = 0;

bool isAvailable(vector<int> numbers, int index){
    // 사이즈 초과
    if(index >= SIZE){
        return false;
    }    
    return true;
}

// index값 계산하고, 다음 index값으로 검사
void search(vector<int> numbers, int cur_sum, int index, int target){
    
    if(index == SIZE && cur_sum == target){
        answer++;
    }
    
    // index값을 넣고, +1된 index값으로 검사
    if(isAvailable(numbers, index)){
        search(numbers, cur_sum+numbers[index], index+1, target);
        search(numbers, cur_sum-numbers[index], index+1, target);
    }
}

int solution(vector<int> numbers, int target) {
    SIZE = numbers.size();
    
    search(numbers,0,0, target);
    
    return answer;
}