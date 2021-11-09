#include <string>
#include <vector>
#include <queue>

using namespace std;

// queue의 첫번째 요소의 우선순위가 가장 큰지 확인
bool is_first_max(queue<int> q){ 
    int std = q.front();
    int max_element = std;
    while(q.size() != 0){
        if(max_element < q.front()){
            max_element = q.front();
        }
        q.pop();
    }
    if(std == max_element){
        return true;
    }
    else{
        return false;
    }
}

int solution(vector<int> priorities, int location) {
    queue<int> myqueue;
    for(auto e: priorities){
        myqueue.push(e);
    }
    
    int index = location;
    int cnt = 0;

    while(1){
        // 원하는 요소가 queue의 front에 위치, front의 우선순위가 가장 높은 경우
        if((index == 0) && (is_first_max(myqueue))){
            // 출력하면서 루프 끝
            cnt += 1;
            break;
        }
        // 원하는 요소가 queue의 front에 위치X, front의 우선순위가 가장 높은 경우
        else if((index != 0) && is_first_max(myqueue)){
            // 출력하고  queue의 위치를 하나 앞당김
            myqueue.pop();
            index -= 1;
            cnt += 1;
        }
        // 원하는 요소가 queue의 front에 위치, front의 우선순위가 가장 높지 않은 경우
        else if((index == 0) && (is_first_max(myqueue) == false)){
            // 원하는 요소를 queue의 맨 뒤로 옮김
            myqueue.push(myqueue.front());
            myqueue.pop();
            index = myqueue.size()-1;
        }
        // 원하는 요소가queue의 front에 위치X, front의 우선순위가 가장 높지 않은 경우
        else if((index != 0) && (is_first_max(myqueue) == false)){
            // queue의 첫번째 요소를 queue의 맨뒤로 옮김
            myqueue.push(myqueue.front());
            myqueue.pop();
            index -= 1;
        }
    }
    return cnt;
}