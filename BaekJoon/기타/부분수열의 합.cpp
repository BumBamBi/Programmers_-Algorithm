#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int N;
int S;
vector<int> v;

// 합, 고려한 개수
void subSet(int sum, int cnt){
    // 모든 숫자를 고려했을 때
    if(cnt == N){
        if(sum == S){
            answer++;
        }
        return;
    }else{
        // 해당 값을 더한 경우
        subSet(sum + v[cnt], cnt + 1);
        // 해당 값을 더하지 않은 경우
        subSet(sum, cnt + 1);
    }
}

int main(){
    cin >> N >> S;

    for (int i = 0; i < N; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    // 합, 고려한 개수
    subSet(0,0);

    
    if(S == 0){
        // 공집한인 경우(아무것도 안 더한 경우) 제외
        cout << answer - 1;
    }else{
        cout << answer;
    }

    return 0;
}
