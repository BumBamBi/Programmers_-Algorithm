#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    // 거리
    vector<long long> distance;
    for(int i=0; i<N-1; i++){
        long long temp;
        cin >> temp;
        distance.push_back(temp);
    }

    // 가격
    vector<long long> cost;
    for(int i=0; i<N; i++){
        long long temp;
        cin >> temp;
        cost.push_back(temp);
    }
    // -------------------------------

    
    // cost가 가장 적은 지역에서 ,추후 사용할 기름 전부 넣기
    long long result = 0;
    while(!distance.empty()){
        
        int min_cost_index = min_element(cost.begin(), cost.end()) - cost.begin();
        long long remained_distnace = 0;

        // 처음 while문에 들어 온 경우에, 가장 낮은 cost인 도시가 마지막 도시라면 남은거리 계산 할 필요X
        // 제거해 나가다가 처음이 가장 비싼 도시였다면(cost.size() == 1), 처음 이동하기 위해 적어도 1회는 주유해야함
        if(min_cost_index != N || cost.size() == 1){
            remained_distnace = accumulate(distance.begin()+min_cost_index, distance.end(), 0);
        }

        // 총 비용 계산
        result += remained_distnace * (cost[min_cost_index]);

        // cost가 가장 적은 지역을 포함한 이후 지역과 거리를 벡터에서 삭제
        cost.erase(cost.begin()+min_cost_index, cost.end());
        distance.erase(distance.begin()+min_cost_index, distance.end());
    }

    cout << result;

    return 0;
}