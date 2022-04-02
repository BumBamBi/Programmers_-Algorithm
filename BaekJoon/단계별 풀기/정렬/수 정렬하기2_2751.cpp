#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool condition(int a, int b){
    return b > a;
}

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    vector<int> v;

    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    // -------------------------------

    sort(v.begin(), v.end(), condition);

    for(auto e:v){
        cout << e << '\n';
    }

    return 0;
}