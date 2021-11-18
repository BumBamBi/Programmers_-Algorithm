#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    // 입력 --------------------------
    int N;
    cin >> N;

    vector<int> v;

    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    // -------------------------------

    vector<int> unique_v = v;
    sort(unique_v.begin(), unique_v.end());
    unique_v.erase(unique(unique_v.begin(), unique_v.end()), unique_v.end());

    for(auto e:v){
        // e 보다 작은 값의 개수 찾기
        cout << lower_bound(unique_v.begin(), unique_v.end(), e) - unique_v.begin() << ' ';
    }
    
    return 0;
}