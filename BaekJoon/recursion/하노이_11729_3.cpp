#include <iostream>
#include <vector>

using namespace std;

int move_biggest(int cnt, int start, int dest, vector<int> &vec){
    // cout 대신 vector에 저장
    vec.push_back(start);
    vec.push_back(dest);
    return 1;
}

int hanoi(int n, int start, int dest, int via, vector<int> &vec){
    if(n == 1){
        // cout 대신 vector에 저장
        vec.push_back(start);
        vec.push_back(dest);
        return 1;
    }else{
        return hanoi(n-1, start, via, dest, vec) + move_biggest(n, start, dest, vec) +hanoi(n-1, via, dest, start, vec);
    }
}

int main(){
    int N;
    cin >> N;

    vector<int> vec;

    int cnt = hanoi(N, 1, 3, 2, vec);

    cout << cnt << endl;

    // 항상 짝수라 +2 씩 더하며 모든 값 출력
    for(int i=1; i<vec.size(); i+=2){
        // endl은 개행문자 + 출력버퍼를 지우는 역할도 한다. 
        // 따라서 endl 대신 '\n'을 출력하면 굉장한 속도향상이 발생함.
        cout << vec[i-1] << ' ' << vec[i] << '\n';
    }

    return 0;
}