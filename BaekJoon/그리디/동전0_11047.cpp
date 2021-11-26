#include <iostream>
#include <vector>

using namespace std;

int main(){

    // 입력 --------------------------
    int N, K;
    cin >> N >> K;

    vector<int> v;
    for(int i=0; i<N; i++){
        int temp;
        cin>> temp;
        v.push_back(temp);
    }
    // -------------------------------

    int remain_money = K;
    int result = 0;
    for(int i = N-1; i >= 0; i--){
        if(remain_money >= v[i]){
            // 해당 금액 동전을 몇개 줄 수 있는지 파악 
            int temp_cnt = remain_money/v[i];
            
            // 줄수 있는 동전 추가
            result += temp_cnt;

            // 동전으로 바꾸고 남은 값 최신화
            remain_money -= temp_cnt * v[i];
        }
        if(remain_money <= 0){
            break;
        }
    }
    
    cout << result;

    return 0;
}