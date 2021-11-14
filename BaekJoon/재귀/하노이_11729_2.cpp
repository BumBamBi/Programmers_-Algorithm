#include <iostream>

using namespace std;

int move_biggest(int cnt, int start, int dest){
    cout << start << ' ' << dest << endl;
    return 1;
}

int hanoi(int n, int start, int dest, int via){
    if(n == 1){
        cout << start << ' ' << dest << endl;
        return 1;
    }else{
        // hanoi와 move_biggest의 반환값을 int로 두고 이동이 일어날 때 마다 1씩 더한 값을 리턴.
        return hanoi(n-1, start, via, dest) + move_biggest(n, start, dest) +hanoi(n-1, via, dest, start);
    }
}

int main(){
    int N;
    cin >> N;

    int cnt = hanoi(N, 1, 3, 2);

    cout << cnt;

    // 그러나 백준의 문제는 출력값이 먼저 나오고, 경로가 표기되어야한다.
    // _3 참조

    return 0;
}