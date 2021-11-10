#include <iostream>

using namespace std;

void move_biggest(int cnt, int start, int dest){
    cout << start << ' ' << dest << endl;
}

void hanoi(int n, int start, int dest, int via){
    if(n == 1){
        cout << start << ' ' << dest << endl;;
    }else{
        // 가장 큰 원판을 제외한 모든 원판을 경유지(via)로 옮기기
        // hanoi(n-1)로 들어간 이후로는, 경유지(via)를 목적지(dest)로 판단 해야함 (어차피 경유지까지만 가는것이 목적이기 때문)
        hanoi(n-1, start, via, dest);

        // 가장 큰 원판을 옮기기
        move_biggest(n, start, dest);

        // 경유지(via)에 있는 원판들을 도착지로 옮기기
        hanoi(n-1, via, dest, start);
    }
}

int main(){
    int N;
    cin >> N;

    hanoi(N, 1, 3, 2);

    return 0;
}