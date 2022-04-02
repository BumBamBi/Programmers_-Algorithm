#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    vector<int> v;
    for(int i=0; i<N; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    // -------------------------------

    // 오름차순 정렬
    sort(v.begin(), v.end());

    int result = 0;
    for(int i=0; i<=N; i++){
        // 최소 시간 = v[0]*N + v[1]*(N-1) + v[2]*(N-2)....
        result = accumulate(v.begin(), v.begin()+i, result);
    }

    cout << result;
    return 0;
}