#include<iostream>
#include<vector>

using namespace std;

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;
    // -------------------------------

    vector<int> v(N+1, 0);

    // f(N) = 00으로 시작하는 경우(f(N-2)) + 1로 시작하는 경우(f(N-1))
    v[1] = 1;
    v[2] = 2;
    for (int i = 3; i <= N; i++){
        // 어차피 15746으로 나눈 나머지만 구하면 되므로 미리 나눠놓음(size초과 방지)
        v[i] = (v[i - 2] + v[i - 1])%15746;
    }

    cout << v[N];

    return 0;
}