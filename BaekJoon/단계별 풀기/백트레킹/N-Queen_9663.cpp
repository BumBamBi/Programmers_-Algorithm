#include <iostream>

#define MAX 15

using namespace std;

// 어차피 퀸을 두면 세로줄에 또 두지 못하기 때문에, 몇번째 행에 있는지 기억하도록 1차원 배열만 이용
int field[MAX];
int N, total = 0;

bool check(int x_idx){
    for(int i = 0; i < x_idx; i++){
        // 같은 행에 있거나, 대각선인 경우엔 False를 리턴
        // i가 의미하는 것이 x좌표, field[i]값이 의미하는것이 y좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
        if(field[i] == field[x_idx] || abs(field[x_idx] - field[i]) == x_idx - i){
            return false;
        }
    }
    return true;
}

void nqueen(int x){
    if(x == N){
        total++;
    }
    else{
        for(int i = 0; i < N; i++){
            // 해당 위치에 퀸을 배치
            field[x] = i; 

            // 유효하다면 다음행에 퀸 배치, 유효하지않다면 다른 위치로 퀸 배치 변경
            if(check(x)){
                nqueen(x+1);
            } 
        }
    }
}

int main() {
    cin >> N;
    nqueen(0);
    cout << total;

    return 0;
}