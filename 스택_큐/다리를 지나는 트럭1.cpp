#include <string>
#include <vector>
#include <queue>

using namespace std;

// 현재 다리위에 올라온 차량의 무게 합
int sum_cur_weight(queue<int> que){
    int result = 0;
    
    while(que.size() != 0){
        result += que.front();
        que.pop();
    }
    return result;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> myqueue;

    // 지나갈 모든 차량의 무게 합
    int total = 0;
    for(auto e:truck_weights){
        total += e;
    }

    // 지나간 차량의 무게 합
    int finish = 0;

    // 다리(큐)를 0으로 채우기
    for(int i=0; i<bridge_length; i++){
        myqueue.push(0);
    }

    int cnt = 0;
    int truck_weights_index = 0;
    
    while(finish != total){
        // 맨 앞에있는 원소(차)를 빼내고
        finish += myqueue.front();
        myqueue.pop();
        
        // 효용량 >= 다리에 남아있는 차들의 무게 + 다리에 들어올 차의 무게      라면 새로운 차 입장
        if(weight >= sum_cur_weight(myqueue) + truck_weights[truck_weights_index]){
            myqueue.push(truck_weights[truck_weights_index]);
            truck_weights_index += 1;
        }
        // 그 외의 경우 빈칸
        else{
            myqueue.push(0);
        }
        cnt += 1;
    }

    return cnt;
}