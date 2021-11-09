#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 우선순위가 가장 큰지 확인하는 함수
bool is_prior(queue<int> _q){
    // 매개변수로 받아온 큐를 복사함.
    queue<int> A(_q);
    
    // 맨 앞의 수를 빼서 std에 저장.
    int std = A.front();
    A.pop();
    
    // std와 큐 안의 우선순위를 비교
    while(!A.empty()){
        // std 보다 높은 우선순위가 아닐 때
        if(std >= A.front()){
            A.pop();
        }
        // std 보다 높은 우선순위일 때
        else{
            return false;
        }
    }
    return true;
}

int solution(vector<int> priorities, int location) {

    // 큐 생성
    queue<int> my_queue;
    
    // 큐에 우선순위 값 push
    for(auto e:priorities){
        my_queue.push(e);
    }
    
    int count = 0;
    
    while(1){
        // 가장 앞의 수의 우선순위가 가장 높을 때
        if(is_prior(my_queue)){
            // 인쇄 후 카운트 + 1
            my_queue.pop();
            count += 1;

            // 인쇄한 문서가 우리가 요청한 문서일 경우
            if(location == 0){
                return count;
            }
            // 인쇄한 문서가 우리가 요청한 문서가 아닐 경우
            else{
                location -= 1;
            }
        }
        else{
            // 인쇄하려 했던 문서를 맨 뒤로 보냄
            int temp_front_value = my_queue.front();
            my_queue.pop();
            my_queue.push(temp_front_value);

            // 인쇄하려 했던 문서가 우리가 요청한 문서일 경우
            if(location == 0){
                // location이 큐의 맨뒤를 가리키도록 함
                location = my_queue.size()-1;
            }
            // 인쇄하려 했던 문서가 우리가 요청한 문서가 아닐 경우
            else{
                location -= 1;
            }
        }
    }
}