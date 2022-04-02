#include <iostream>
#include <vector>

using namespace std;

int main(){

    // 입력 --------------------------
    int N;
    int target;

    cin >> N >> target;

    vector<int> vec;
    vector<bool> isUsed(N, false);
    int temp;

    for(int i=0; i<N; i++){
        cin >> temp;
        vec.push_back(temp);
    }
    // -------------------------------

    // 결과를 저장할 변수
    int result = 0;

    // 3개의 카드를 선택하는 모든 경우의 수
    for(int i=0; i<vec.size()-2; i++){
        for(int j=i+1; j<vec.size()-1; j++){
            for(int k=j+1; k<vec.size(); k++){

                int cur_sum = vec[i]+vec[j]+vec[k];

                // 조건에 맞는 결과인지 매번 확인 
                if( cur_sum <= target && cur_sum > result ){
                    result = cur_sum;
                }
            }
        }
    }

    // 출력
    cout << result;

    return 0;
}