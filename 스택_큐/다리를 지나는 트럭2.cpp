#include <string>
#include <vector>
#include <queue>

using namespace std;

// 다리의 총 무게
int what_bridge_wieght(queue<int> _q){
    
    queue<int> temp(_q);
    int ret = 0;
    
    while(!temp.empty()){
        ret += temp.front();
        temp.pop();
    }
    return ret;
}

// 다리에 트럭이 들어가도록 함 
void enter_trucks(queue<int> &_q, int _n){
    _q.pop();
    _q.push(_n);
    return;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    // queue를 다리로 생각하고 length만큼 0으로 채움
    queue<int> q;
    for(int i=0; i<bridge_length; i++){
        q.push(0);
    }
    
    // 타임 카운트
    int time_cnt = 0;

    // truck 요소만큼 반복
    for(auto e:truck_weights){
        // 효용량 >= 다리에 남아있는 차들의 무게 + 다리에 들어올 차의 무게라면
        if(weight >= what_bridge_wieght(q) + e){
            // 다리에 차 입장
            enter_trucks(q, e);
            time_cnt += 1;
        }
        // 그렇지 않다면
        else{
            // 효용량 >= 다리에 남아있는 차들의 무게 + 다리에 들어올 차의 무게 - 맨앞의 무게가 될동안
            while(weight < what_bridge_wieght(q) + e- q.front()){
                // 0 입장
                enter_trucks(q, 0);
                time_cnt += 1;
            }
            // 효용이 가능해지면 다리에 차 입장
            enter_trucks(q, e);
            time_cnt += 1;
        }
    }
    
    // 다리에 남아있는 차량이 전부 빠질때까지 반복
    while(what_bridge_wieght(q) != 0){
        enter_trucks(q, 0);
        time_cnt += 1;
    }
    
    return time_cnt;
}