#include <iostream>
#include <vector>

using namespace std;

int main(){

    // stdio.h와 싱크를 false 시킴으로써, 속도향상이 일어남
    ios_base::sync_with_stdio(false);

    // 입력 --------------------------
    int N;
    cin >> N;

    vector<int> v(10001,0);

    for(int i=0; i<N; i++){
        int input;
        cin >> input;
        v[input] += 1;
    }
    // -------------------------------

    for(int i=1; i<10001; i++){
        if(v[i] > 0){
            for(int j=0; j<v[i]; j++){
                cout << i << '\n';
            }
        }
    }
    return 0;
}